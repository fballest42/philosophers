alias vscode="/Applications/Visual\ Studio\ Code.app/contents/Resources/app/bin/code"
alias normi="/usr/local/bin/norminette"
alias ga="git add ."; export GDATE=$(date)
alias gm='git commit -m "$GDATE"'
alias gp="git push"
alias gt="ga ; gm ; gp"
export PATH=$HOME/.brew/bin:$PATH
PROMPT='%B%F{yellow}Nano > %f%b'
# Load Homebrew config script
source $HOME/.brewconfig.zsh
