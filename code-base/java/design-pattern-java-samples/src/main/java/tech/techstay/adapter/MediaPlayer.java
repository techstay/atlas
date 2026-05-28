package tech.techstay.adapter;

public interface MediaPlayer {
  void play();
}


class MediaPlayerAdapter implements MediaPlayer {
  private MusicPlayer musicPlayer;
  private VideoPlayer videoPlayer;
  private boolean isMusicPlayer = false;
  private boolean isVideoPlayer = false;

  public MediaPlayerAdapter(Object player) {
    if (player instanceof MusicPlayer) {
      musicPlayer = (MusicPlayer) player;
      isMusicPlayer = true;
    } else if (player instanceof VideoPlayer) {
      videoPlayer = (VideoPlayer) player;
      isVideoPlayer = true;
    }
  }

  @Override
  public void play() {
    if (isMusicPlayer) {
      musicPlayer.playMusic();
    } else if (isVideoPlayer) {
      videoPlayer.playVideo();
    }
  }
}
