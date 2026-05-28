package tech.techstay.adapter;

public class AdapterSample {
  public static void main(String[] args) {
    MusicPlayer musicPlayer = new MyMusicPlayer();
    VideoPlayer videoPlayer = new MyVideoPlayer();

    MediaPlayer player1 = new MediaPlayerAdapter(musicPlayer);
    player1.play();

    MediaPlayer player2 = new MediaPlayerAdapter(videoPlayer);
    player2.play();
  }
}
