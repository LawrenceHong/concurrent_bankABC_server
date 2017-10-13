package redis;
import java.util.Set;

import redis.clients.jedis.Jedis;

/**
 * Created by hongleyou on 2017/3/6.
 */

public class RedisHelper {
    private String address;
    private Jedis jedis;
    private int port;

    public RedisHelper(String address, int port) {
        this.address = address;
        jedis = new Jedis(address);
        this.port = port;
    }

    public void SetInfo(String key, String jsonStr) {
        jedis.set(key, jsonStr);
    }

    public String GetInfo(String key) {
        if(key == null) {
            return "Key is null";
        }

        return jedis.get(key);
    }

    public boolean HasKey(String key) {
        try {
            return jedis.exists(key);
        } catch (Exception e) {
            //e.printStackTrace();
            return false;
        }
    }

    public void RemoveInfo(String key) {
        jedis.del(key);
    }

    public Set<String> GetKeys(String pattern) {
        return jedis.keys(pattern);
    }

    public Set<String> GetSet(String key) {
        return jedis.smembers(key);
    }

    public void SetSet(String key, String member) {
        jedis.sadd(key, member);
    }

    public void RemoveMemberFromSet(String key, String member) {
        jedis.srem(key, member);
    }
}
