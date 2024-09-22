from pytube import Playlist

def download_playlist(playlist_url, output_dir):
    """Downloads a YouTube playlist to the specified directory.

    Args:
        playlist_url: The URL of the YouTube playlist.
        output_dir: The directory where the videos will be downloaded.
    """
    playlist = Playlist(playlist_url)
    print(f"Downloading playlist: {playlist.title}")
    
    # Loop through all videos in the playlist and download
    for video in playlist.videos:
        print(f"Downloading: {video.title}")
        video.streams.get_highest_resolution().download(output_dir)
    print("Download complete.")

if __name__ == "__main__":
    playlist_url = "https://www.youtube.com/playlist?list=PLp2eAGIFKMEWb3PjNdXskeTm7q0f8nEJ8"
    output_dir = "D:/NumberTheoryCourse"
    
    download_playlist(playlist_url, output_dir)
