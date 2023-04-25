package yitian.study.adapter;

public interface MusicPlayer {
    void playMusic();
}

class MyMusicPlayer implements MusicPlayer {

    @Override
    public void playMusic() {
        System.out.println("播放音乐");
    }
}