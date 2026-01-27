import argparse
import requests
import subprocess
from git import Repo

import decomp_settings
import mapfile_parser

repo = Repo('.')

def main(args):
    progress = subprocess.run(
        [ "python3", "-m", "mapfile_parser", "objdiff_report", "--version", "us" ],
        capture_output=True, text=True, check=True
    )
    progress_msg = progress.stdout

    commit = repo.heads.main.commit
    commit_msg = commit.message.splitlines()[0]

    content = {
        "embeds": [{
            "title": f"{commit_msg}",
            "description": f"```{progress_msg}```",
            "url": f"https://github.com/gcsmith/Pilotwings64Decomp/commit/{commit.hexsha}",
            "color": commit.authored_date & 0xFFFFFF
        }]
    }
    requests.post(args.discord_url, json=content)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Publish objdiff_report to Discord server")
    parser.add_argument("--discord_url", help="Discord webhook URL", required=True)
    args = parser.parse_args()
    main(args)

