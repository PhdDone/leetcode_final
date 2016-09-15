//http://www.cnblogs.com/grandyang/p/5577038.html

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
  follow(followerId, followeeId): Follower follows a followee.
  unfollow(followerId, followeeId): Follower unfollows a followee.
  Example:

  Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);

//my bug sol

class Twitter {
private:
  unordered_map<int, unordered_set<int>> friends_;
  unordered_map<int, vector<pair<int, int>>> tweets_;
  int cnt_ = 0;
public:
  /** Initialize your data structure here. */
  Twitter() {

  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    follow(userId, userId); //Add user to be his own friend.
    tweets_[userId].push_back({cnt_++, tweetId});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> top10;
    //use great so that the smallest is always at the front, just pop when size > 10;
    auto followees = friends_[userId];
    for (auto f : followees) {
      auto tweets = tweets_[f];
      for (auto& t : tweets) {
        // optimization!! if top10 is not empty and top10.top().cnt > current cnt of this tweets and
        // top10.size() >= 10, early stop!!
        // because tweets is sorted by cnt
        // check empty before top
        // bug here, use top10.size() > 10, but will never reach then??
        if (!top10.empty() && top10.top().first > t.first && top10.size() >= 10) break;
        top10.push(t);
        if (top10.size() > 10) {
          top10.pop();
        }
      }
    }
    vector<int> res;
    while (!top10.empty()) {
      res.push_back(top10.top().second);
      top10.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    friends_[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      friends_[followerId].erase(followeeId);
    }
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */


class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() {
    cnt = 0;
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    follow(userId, userId);
    tweets[userId].push_back({cnt++, tweetId});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (auto it = friends[userId].begin(); it != friends[userId].end(); ++it) {
      for (auto a = tweets[*it].begin(); a != tweets[*it].end(); ++a) {
        if (q.size() > 0 && q.top().first > a->first && q.size() > 10) break;
        q.push(*a);
        if (q.size() > 10) q.pop();
      }
    }
    while (!q.empty()) {
      res.push_back(q.top().second);
      q.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    friends[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      friends[followerId].erase(followeeId);
    }
  }

private:
  int cnt;
  unordered_map<int, set<int>> friends;
  unordered_map<int, vector<pair<int, int>>> tweets;
};
