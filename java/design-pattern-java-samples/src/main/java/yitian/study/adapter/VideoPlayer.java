package yitian.study.adapter;

public interface VideoPlayer {
    void playVideo();
}

class MyVideoPlayer implements VideoPlayer{

    @Override
    public void playVideo() {
        System.out.println("播放视频");
    }
}