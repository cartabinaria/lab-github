git mergetool
GIT-MERGETOOL(1)                Git Manual                GIT-MERGETOOL(1)

NAME
       git-mergetool - Run merge conflict resolution tools to resolve
       merge conflicts

SYNOPSIS
       git mergetool [--tool=<tool>] [-y | --[no-]prompt] [<file>...]

DESCRIPTION
       Use git mergetool to run one of several merge utilities to resolve
       merge conflicts. It is typically run after git merge.

       If one or more <file> parameters are given, the merge tool program
       will be run to resolve differences in each file (skipping those
       without conflicts). Specifying a directory will include all
       unresolved files in that path. If no <file> names are specified,
       git mergetool will run the merge tool program on every file with
       merge conflicts.
PRACTICAL USER DESCRIPTION
       Risolving conflicts after a merge is a fundamental aspect of a repository, mergetools help you resolve these.
       As I still haven't used it I shall update it with tips when I've used it
OPTIONS
       -t <tool>, --tool=<tool>
           Use the merge resolution program specified by <tool>. Valid
           values include emerge, gvimdiff, kdiff3, meld, vimdiff, and
           tortoisemerge. Run git mergetool --tool-help for the list of
           valid <tool> settings.

           If a merge resolution program is not specified, git mergetool
           will use the configuration variable merge.tool. If the
           configuration variable merge.tool is not set, git mergetool
           will pick a suitable default.

           You can explicitly provide a full path to the tool by setting
           the configuration variable mergetool.<tool>.path. For example,
           you can configure the absolute path to kdiff3 by setting
           mergetool.kdiff3.path. Otherwise, git mergetool assumes the
           tool is available in PATH.

           Instead of running one of the known merge tool programs, git
           mergetool can be customized to run an alternative program by specifying the command line to invoke in a configuration
           variable mergetool.<tool>.cmd.

           When git mergetool is invoked with this tool (either through
           the -t or --tool option or the merge.tool configuration
           variable), the configured command line will be invoked with
           $BASE set to the name of a temporary file containing the common
           base for the merge, if available; $LOCAL set to the name of a
           temporary file containing the contents of the file on the
           current branch; $REMOTE set to the name of a temporary file
           containing the contents of the file to be merged, and $MERGED
           set to the name of the file to which the merge tool should
           write the result of the merge resolution.

           If the custom merge tool correctly indicates the success of a
           merge resolution with its exit code, then the configuration
           variable mergetool.<tool>.trustExitCode can be set to true.
           Otherwise, git mergetool will prompt the user to indicate the
           success of the resolution after the custom tool has exited.

       --tool-help
           Print a list of merge tools that may be used with --tool.

       -y, --no-prompt
           Don’t prompt before each invocation of the merge resolution
           program. This is the default if the merge resolution program is
           explicitly specified with the --tool option or with the
           merge.tool configuration variable.

       --prompt
           Prompt before each invocation of the merge resolution program
           to give the user a chance to skip the path.

       -g, --gui
           When git-mergetool is invoked with the -g or --gui option, the
           default merge tool will be read from the configured
           merge.guitool variable instead of merge.tool. If merge.guitool
           is not set, we will fallback to the tool configured under
           merge.tool. This may be autoselected using the configuration

       --no-gui
           This overrides a previous -g or --gui setting or
           mergetool.guiDefault configuration and reads the default merge
           tool from the configured merge.tool variable.

       -O<orderfile>
           Process files in the order specified in the <orderfile>, which
           has one shell glob pattern per line. This overrides the
           diff.orderFile configuration variable (see git-config(1)). To
           cancel diff.orderFile, use -O/dev/null.

--------------------------------------------------------------------------------------------------------------------------------
git checkout -b
GIT-CHECKOUT(1)                                       Git Manual                                      GIT-CHECKOUT(1)

NAME
       git-checkout - Switch branches or restore working tree files

SYNOPSIS
       git checkout [-q] [-f] [-m] [<branch>]
       git checkout [-q] [-f] [-m] --detach [<branch>]
       git checkout [-q] [-f] [-m] [--detach] <commit>
       git checkout [-q] [-f] [-m] [[-b|-B|--orphan] <new-branch>] [<start-point>]
       git checkout [-f] <tree-ish> [--] <pathspec>...
       git checkout [-f] <tree-ish> --pathspec-from-file=<file> [--pathspec-file-nul]
       git checkout [-f|--ours|--theirs|-m|--conflict=<style>] [--] <pathspec>...
       git checkout [-f|--ours|--theirs|-m|--conflict=<style>] --pathspec-from-file=<file> [--pathspec-file-nul]
       git checkout (-p|--patch) [<tree-ish>] [--] [<pathspec>...]

DESCRIPTION
       Updates files in the working tree to match the version in the index or the specified tree. If no pathspec was
       given, git checkout will also update HEAD to set the specified branch as the current branch.

       git checkout [<branch>]
           To prepare for working on <branch>, switch to it by updating the index and the files in the working tree,
           and by pointing HEAD at the branch. Local modifications to the files in the working tree are kept, so that
           they can be committed to the <branch>.

           If <branch> is not found but there does exist a tracking branch in exactly one remote (call it <remote>)
           with a matching name and --no-guess is not specified, treat as equivalent to

               $ git checkout -b <branch> --track <remote>/<branch>
 
           You could omit <branch>, in which case the command degenerates to "check out the current branch", which is
           a glorified no-op with rather expensive side-effects to show only the tracking information, if it exists,
           for the current branch.

#       git checkout -b|-B <new-branch> [<start-point>]
           Specifying -b causes a new branch to be created as if git-branch(1) were called and then checked out. In
           this case you can use the --track or --no-track options, which will be passed to git branch. As a
           convenience, --track without -b implies branch creation; see the description of --track below.

           If -B is given, <new-branch> is created if it doesn’t exist; otherwise, it is reset. This is the
           transactional equivalent of

               $ git branch -f <branch> [<start-point>]
               $ git checkout <branch>

           that is to say, the branch is not reset/created unless "git checkout" is successful.
----------------------------------------------------------------------------------------------------------------------------
git rebase --exec "<cmd>"
GIT-REBASE(1)                                         Git Manual
                            GIT-REBASE(1)

NAME
       git-rebase - Reapply commits on top of another base tip

SYNOPSIS
       git rebase [-i | --interactive] [<options>] [--exec <cmd>]
               [--onto <newbase> | --keep-base] [<upstream> [<branch>]]
       git rebase [-i | --interactive] [<options>] [--exec <cmd>] [--onto <n
ewbase>]
               --root [<branch>]
       git rebase (--continue | --skip | --abort | --quit | --edit-todo | --
show-current-patch)

DESCRIPTION
       If <branch> is specified, git rebase will perform an automatic git sw
itch <branch> before doing anything else.
       Otherwise it remains on the current branch.

       If <upstream> is not specified, the upstream configured in branch.<na
me>.remote and branch.<name>.merge
       options will be used (see git-config(1) for details) and the --fork-p
oint option is assumed. If you are
       currently not on any branch or if the current branch does not have a
configured upstream, the rebase will
       abort.

       All changes made by commits in the current branch but that are not in
 <upstream> are saved to a temporary
       area. This is the same set of commits that would be shown by git log <upstream>..HEAD; or by git log
       'fork_point'..HEAD, if --fork-point is active (see the description on --fork-point below); or by git log HEAD,
       if the --root option is specified.

       The current branch is reset to <upstream> or <newbase> if the --onto option was supplied. This has the exact
       same effect as git reset --hard <upstream> (or <newbase>). ORIG_HEAD is set to point at the tip of the branch before the reset.
PRACTICAL USER DESCRIPTION
	When doing a rebase, the --exec <cmd> flag means that it will run the chosen shell script and execute it for every commit that the rebase is going to consider.
	A useful example i looked up somewhere is utilizing a formatter, for example: 
	git rebase -i --exec 'prettier --write {**/*,*}.js' ffcfe45
	Will use the prettier shell to modify all of the .js files through the rebase
--------------------------------------------------------------------------
git merge --squash
GIT-MERGE(1)                    Git Manual                    GIT-MERGE(1)

NAME
       git-merge - Join two or more development histories together

SYNOPSIS
       git merge [-n] [--stat] [--no-commit] [--squash] [--[no-]edit]
               [--no-verify] [-s <strategy>] [-X <strategy-option>] [-S[<key
id>]]
               [--[no-]allow-unrelated-histories]
               [--[no-]rerere-autoupdate] [-m <msg>] [-F <file>]
               [--into-name <branch>] [<commit>...]
       git merge (--continue | --abort | --quit)

DESCRIPTION
       Incorporates changes from the named commits (since the time their
       histories diverged from the current branch) into the current
       branch. This command is used by git pull to incorporate changes
       from another repository and can be used by hand to merge changes
       from one branch into another.

       Assume the following history exists and the current branch is
       "master":

                     A---B---C topic
                    /
               D---E---F---G master

       Then "git merge topic" will replay the changes made on the topic
       branch since it diverged from master (i.e., E) until its current
       commit (C) on top of master, and record the result in a new commit
       along with the names of the two parent commits and a log message
       from the user describing the changes. Before the operation,
       ORIG_HEAD is set to the tip of the current branch (C).

                     A---B---C topic
                    /         \
               D---E---F---G---H master

       The second syntax ("git merge --abort") can only be run after the 
       merge has resulted in conflicts. git merge --abort will abort the
       merge process and try to reconstruct the pre-merge state. However,
       if there were uncommitted changes when the merge started (and
       especially if those changes were further modified after the merge
       was started), git merge --abort will in some cases be unable to
       reconstruct the original (pre-merge) changes. Therefore:

       Warning: Running git merge with non-trivial uncommitted changes is
       discouraged: while possible, it may leave you in a state that is
       hard to back out of in the case of a conflict.

       The third syntax ("git merge --continue") can only be run after the
       merge has resulted in conflicts.

OPTIONS
       --squash, --no-squash
           Produce the working tree and index state as if a real merge
           happened (except for the merge information), but do not
           actually make a commit, move the HEAD, or record
           $GIT_DIR/MERGE_HEAD (to cause the next git commit command to
           create a merge commit). This allows you to create a single
           commit on top of the current branch whose effect is the same as
           merging another branch (or more in case of an octopus).

           With --no-squash perform the merge and commit the result. This
           option can be used to override --squash.

           With --squash, --commit is not allowed, and will fail.
---------------------------------------------------------------------------
git reset --keep
GIT-RESET(1)                    Git Manual                    GIT-RESET(1)

NAME
       git-reset - Reset current HEAD to the specified state

SYNOPSIS
       git reset [-q] [<tree-ish>] [--] <pathspec>...
       git reset [-q] [--pathspec-from-file=<file> [--pathspec-file-nul]] [<tree-ish>]
       git reset (--patch | -p) [<tree-ish>] [--] [<pathspec>...]
       git reset [--soft | --mixed [-N] | --hard | --merge | --keep] [-q] [<commit>]

DESCRIPTION
       In the first three forms, copy entries from <tree-ish> to the
       index. In the last form, set the current branch head (HEAD) to
       <commit>, optionally modifying index and working tree to match. The
       <tree-ish>/<commit> defaults to HEAD in all forms.

       git reset [-q] [<tree-ish>] [--] <pathspec>..., git reset [-q]
       [--pathspec-from-file=<file> [--pathspec-file-nul]] [<tree-ish>]
           These forms reset the index entries for all paths that match
           the <pathspec> to their state at <tree-ish>. (It does not
           affect the working tree or the current branch.)

           This means that git reset <pathspec> is the opposite of git add
           <pathspec>. This command is equivalent to git restore
           [--source=<tree-ish>] --staged <pathspec>....

           After running git reset <pathspec> to update the index entry,
           you can use git-restore(1) to check the contents out of the
           index to the working tree. Alternatively, using git-restore(1)
           and specifying a commit with --source, you can copy the
           contents of a path out of a commit to the index and to the
           working tree in one go.

       git reset (--patch | -p) [<tree-ish>] [--] [<pathspec>...]
           Interactively select hunks in the difference between the index
           and <tree-ish> (defaults to HEAD). The chosen hunks are applied
           in reverse to the index.

	This means that git reset -p is the opposite of git add -p,
           i.e. you can use it to selectively reset hunks. See the
           “Interactive Mode” section of git-add(1) to learn how to
           operate the --patch mode.

       git reset [<mode>] [<commit>]
           This form resets the current branch head to <commit> and
           possibly updates the index (resetting it to the tree of
           <commit>) and the working tree depending on <mode>. Before the
           operation, ORIG_HEAD is set to the tip of the current branch.
           If <mode> is omitted, defaults to --mixed. The <mode> must be
           one of the following:

           --soft
               Does not touch the index file or the working tree at all
               (but resets the head to <commit>, just like all modes do).
               This leaves all your changed files "Changes to be
               committed", as git status would put it.

           --mixed
               Resets the index but not the working tree (i.e., the
               changed files are preserved but not marked for commit) and
               reports what has not been updated. This is the default
               action.

               If -N is specified, removed paths are marked as
               intent-to-add (see git-add(1)).

           --hard
               Resets the index and working tree. Any changes to tracked
               files in the working tree since <commit> are discarded. Any
               untracked files or directories in the way of writing any
               tracked files are simply deleted.

           --merge
               Resets the index and updates the files in the working tree
               that are different between <commit> and HEAD, but keeps
               those which are different between the index and working
               tree (i.e. which have changes which have not been added).
	 In other words, --merge does something like a git read-tree
               -u -m <commit>, but carries forward unmerged index entries.

           --keep
               Resets index entries and updates files in the working tree
               that are different between <commit> and HEAD. If a file
               that is different between <commit> and HEAD has local
               changes, reset is aborted.

           --[no-]recurse-submodules
               When the working tree is updated, using
               --recurse-submodules will also recursively reset the
               working tree of all active submodules according to the
               commit recorded in the superproject, also setting the
               submodules' HEAD to be detached at that commit.

       See "Reset, restore and revert" in git(1) for the differences
       between the three commands.
--------------------------------------------------------------------------
git bisect, bellissimo questo
GIT-BISECT(1)                   Git Manual                   GIT-BISECT(1)

NAME
       git-bisect - Use binary search to find the commit that introduced a
       bug

SYNOPSIS
       git bisect <subcommand> <options>

DESCRIPTION
       The command takes various subcommands, and different options
       depending on the subcommand:

           git bisect start [--term-(new|bad)=<term-new> --term-(old|good)=<
term-old>]
                            [--no-checkout] [--first-parent] [<bad> [<good>.
..]] [--] [<paths>...]
           git bisect (bad|new|<term-new>) [<rev>]
           git bisect (good|old|<term-old>) [<rev>...]
           git bisect terms [--term-good | --term-bad]
           git bisect skip [(<rev>|<range>)...]
           git bisect reset [<commit>]
           git bisect (visualize|view)
           git bisect replay <logfile>
           git bisect log
           git bisect run <cmd> [<arg>...]
           git bisect help

       This command uses a binary search algorithm to find which commit in
       your project’s history introduced a bug. You use it by first
       telling it a "bad" commit that is known to contain the bug, and a
       "good" commit that is known to be before the bug was introduced.
       Then git bisect picks a commit between those two endpoints and asks
       you whether the selected commit is "good" or "bad". It continues
       narrowing down the range until it finds the exact commit that
       introduced the change.
Questo non l'ho introdotto tutto perchè mi sembra molto bellino e quindi quando avrò voglia di leggerlo lo leggerò direttamente dalle man pages
