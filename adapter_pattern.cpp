/*
 *Adapter Pattern is used as communicator between two different class
 */
#include <iostream>
#include <string>
using namespace std;

class Iplay
{
  public:
    virtual void play() = 0;
};

class OldMusicPlayer
{
  string song_;
  public:
  OldMusicPlayer(string song)
  {
    song_ = song;
    
  }
 
  void oldPlay(int volume)
  {
    cout<<"Playing Song "<< song_ <<" at volume "<<volume;
  } 

};

class IplayToOldMusicPlayerAdapter : private OldMusicPlayer, public Iplay
{
  
  int volume;
  public:

  IplayToOldMusicPlayerAdapter(string song, int volume)  : OldMusicPlayer(song)
  {
    this->volume = volume;
  }

  virtual void play()
  {
    oldPlay(volume);
  }

};

int main()
{
 
 Iplay *ModernPlayer = new IplayToOldMusicPlayerAdapter("La La La..!!", 10);  
 ModernPlayer->play();
 return 0;
}










