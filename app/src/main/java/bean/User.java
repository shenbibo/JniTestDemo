package bean;

/**
 * bean
 * [function]
 * [detail]
 * Created by Sky on 2016/9/24.
 * modify by
 */

public class User {
    private int userId;

    private String userName;

    public User(int id, String name){
        userId = id;
        userName = name;
    }

    @Override
    public String toString() {
        return "userId = " + userId + ", userName = " + userName;
    }
}
