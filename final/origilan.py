import tweepy
from keys import *

# Use your Twitter API keys to connect
auth = tweepy.OAuthHandler(cskey,cssecret)
auth.set_access_token(acctok,acctoksec)

api = tweepy.API(auth_handler=auth, wait_on_rate_limit_notify=True,wait_on_rate_limit=True)

print "termine"
public_tweets = api.home_timeline()
for tweet in public_tweets:
    print tweet.text
