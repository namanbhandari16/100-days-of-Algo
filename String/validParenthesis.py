
#Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.


def isValidParenthesis(str):

    stack = [] 

    # Hash map for keeping track of mappings
    mapping ={")":"(","}":"{","]":"["}
    
    status = True

    for i in str:

        #if i is opening parenthesis push it in stack
        if(not stack or i in {"(","{","["}):
            stack.append(i)
        else:

            # if top element does not match with closing parenthesis then return False
            if(stack.pop() != mapping[i]):
                return False

    if(stack):
        return False
    return True


input = "[][{}{}]"
print(isValidParenthesis(input))
        