#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
 class Comparator_1 {
   public:
    bool operator() (const Song s1, const Song s2) const {
      if(s1.artist != s2.artist) return s1.artist > s2.artist;
      return s1.title > s2.title;
    }
 }; 

class Comparator_2 {
  public:
    bool operator() (const Song s1, const Song s2) const {
      if(s1.count != s2.count) return s1.count < s2.count;
      if(s1.artist != s2.artist) return s1.artist > s2.artist;
      return s1.title > s2.title;
    }
};

CP::priority_queue<Song , Comparator_1> pq1;
CP::priority_queue<Song , Comparator_2> pq2;

#endif