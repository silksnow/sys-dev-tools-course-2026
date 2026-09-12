# app.py
import os
from flask import Flask
import redis

app = Flask(__name__)
r = redis.Redis(host=os.environ.get("REDIS_HOST", "localhost"),
                port=6379, decode_responses=True)

@app.route("/")
def home():
    return f"访问次数: {r.incr('hits')}"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)