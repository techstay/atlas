package yitian.study.dao


interface UserRepository {
    void add(User user)

    List<User> listAll()
}
