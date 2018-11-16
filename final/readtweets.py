import tweepy
import pandas as pd
from os import environ
from keys import *

# Use your Twitter API keys to connect
auth = tweepy.OAuthHandler(cskey,cssecret)
auth.set_access_token(acctok,acctoksec)

api = tweepy.API(auth_handler=auth, wait_on_rate_limit_notify=True,wait_on_rate_limit=True)

print "termine"

# If the authentication was successful, you should
# see the name of the account print out
print(api.me().name)

# If the application settings are set for "Read and Write" then
# this line should tweet out the message to your account's
# timeline. The "Read and Write" setting is on https://dev.twitter.com/apps
api.update_status(status='Updating using OAuth authentication via Tweepy!')

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
print data
data.to_csv("twitter.csv", sep='\t', index=False)
