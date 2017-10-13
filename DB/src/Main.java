import CMD.BankServer;
import redis.RedisHelper;

/**
 * Created by hongleyou on 2017/10/9.
 */
public class Main {
    public static void main(String[] args) {
        main_method(args[0]);
    }
    public static void main_method(String sargs) {
        System.out.println("Enter main");


        System.out.println(sargs);
        String[] args = sargs.split("#");
        System.out.println(BankServer.Process(args[0], Integer.valueOf(args[1]), args[2]));
    }
}
