# Final Project



---

### Goal: 
    Produce a fully functional interactive School Managment Application within the console in C++ that students can personally use throughout their educations or to add to their portfolios/resumes.

## Base Concept:
    This will be a School Managment System(SMS) built as a console application in C++ that is built on a REPL granting access as well as exception handling for the user to input commands. The user must have the ability to add students, addcourse, filter students from the roster by id or family name, filter students by courses, as well as all of the base functionality implemented in the Grade Report project including grade calculation, gpa calculation, and printing functionality.



---
###
Staging is updated frequently throughout the day.
Master is updated at the end of the day from staging.

---
# Git flow cheat sheet
**Push your work to your branch**
On your branch, you did some work...
>`git add .`
`git commit -m` ^1^
`git push origin your-branch-name`

now you want to pull into staging. Good.

To do that, you can checkout staging, and get the most updated version like this:
>`git checkout staging`
`git pull origin staging`

Pulling staging into staging _should_ go really smooth. All it's doing is updating your version of staging with the newest version of staging that is live. When you do it, you should see a message at the top of the list of files that says _Fast forward_.

Up to now, we've simply updated our local staging with the updated staging. The above process should be done, **at least**, once a day.

**Pull your branch into local staging**
Now, you are on the staging branch locally and your staging branch is all up to date. Do this:
>`git pull origin your-branch-name`

Ideally, you'll see another _Fast forward_^2^ and you can proceed with committing. 

Alternatively, you may run into _merge conflicts_. That's ok, it happens!

**In the event of a merge conflict**
Anytime two people work on the same file during the same time, the potential for a conflict exists. 

BUT, VSCode makes it really easy to see and handle such conflicts. 

Click on the github icon in VS, review the merge changes (these are the first in the first section) one by one and then decide what the best course of action will be.

Remember, save each file after you resolve the conflict!

Remember, commit each file after you resolve the conflict!

**Push your newly updated staging**
Now, you have an updated staging. After handling any conflicts, don't forget to review the app to make sure nothing unexpected happened. 

IF the app looks clean, the changes are good, and your ready to deploy the updated staging server, do this:
>`git push origin staging`
`git checkout -b new-branch-name`


**Notes**
^1^ _Or `git commit` if you're using gitmoji with the hook_
^2^ _Merged using recursive strategy sometimes happens_





