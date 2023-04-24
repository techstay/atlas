package yitian.study.dao

import java.time.LocalDate


class UserRepositoryImpl implements UserRepository {
    private List<User> users

    UserRepositoryImpl() {
        users = new ArrayList<>()
    }

    @Override
    void add(User user) {
        def newId = users*.id.max() ?: 0 + 1
        user.id = newId
        user.registerDate = LocalDate.now()
        users << user
    }

    @Override
    List<User> listAll() {
        return users
    }
}
