/* -------------------------------------------------------------------------- */
/*                                   Stacks                                   */
/* -------------------------------------------------------------------------- */

import scala.collection.mutable.Stack

val stack = Stack(1, 2, 3)

// Basic operations
stack.push(4)
stack.push(5)
stack.pop()
stack

stack.top
stack

stack.isEmpty
stack.size
stack.clear()
stack

stack.pushAll(Stack(6, 7, 8))
stack

stack.popAll()
stack
