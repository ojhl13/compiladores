import tweepy
import pandas as pd
from os import environ
from keys import *
import file
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


def get_timeline_data():

    
    # construct the dataframe
    for tweet in tweepy.Cursor(api.user_timeline, include_rts=False).items():


    tweets = pd.DataFrame(data=tweets_list,
                          columns=['text'])

    return tweets


