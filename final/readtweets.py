import tweetpy
import pandas as pd
from os import environ

# Use your Twitter API keys to connect
cskey=environ["TWITTER_CONSUMER_KEY"]
cssecret=environ["TWITTER_CONSUMER_SECRET"]
auth = tweetpy.OAuthHandler(cskey,cssecret)
acctok=environ["TWITTER_ACCESS_TOKEN"]
acctoksec=environ["TWITTER_ACCESS_TOKEN_SECRET"]
auth.set_access_token(acctok,acctoksec)

api = tweetpy.API(auth_handler=auth, wait_on_rate_limit_notify=True,wait_on_rate_limit=True)

print "termine"
raw_imput()


def get_timeline_data():

    tweets_list = []
    # construct the dataframe
    for tweet in tweepy.Cursor(api.user_timeline, include_rts=False).items():

        tweets_list.append([str(tweet.id), int(tweet._json['favorite_count']),
                            str(tweet._json['retweet_count']), tweet.created_at])

    tweets = pd.DataFrame(data=tweets_list,
                          columns=['id', 'like', 'retweet', 'date'])

    return tweets

data = get_timeline_data()
data.to_csv("twitter.csv", sep='\t', index=False)
