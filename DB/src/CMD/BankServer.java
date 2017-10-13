package CMD;

import redis.RedisHelper;

/**
 * Created by hongleyou on 2017/10/9.
 */
public class BankServer {

    public static String Process(String serverAddr, Integer port, String data) {
        String[] strs = parser(data);
        RedisHelper redisHelper = new RedisHelper(serverAddr, port);
        String cmd = strs[0];
        String account = strs[1];
        return command(redisHelper, cmd, account, strs[2]);
    }

    private static String[] parser(String data) {
        if ("".equals(data) || !data.contains("@")) return null;
        String[] strs = data.split("@");
        if(strs.length < 3) return null;
        return strs;
    }

    private static String command(RedisHelper redisHelper, String cmd, String account, String num) {
        Integer snum = Integer.valueOf(num);
        if("".equals(cmd) || "".equals(account) || snum < 0) return "Error Invalid Parameter";
        if(!redisHelper.HasKey(account)) return "Error Account not found";
        Integer sum = Integer.valueOf(redisHelper.GetInfo(account));
        if(cmd.equals("deposit")) {
            sum += snum;
        }
        else if(cmd.equals("withdrawals")) {
            sum -= snum;
        }
        else return "Error Invalid command";

        if (sum < 0) return "Error Insufficient balance";
        redisHelper.SetInfo(account, String.valueOf(sum));
        return "Execution Succeed";
    }
}
