func factorial(n: Int) -> Int {
     var result = 1
     if(n > 0) {
         for i in 1...n {
             result *= i
         }
     }
     return result
 }

 let num = 4
 let result = factorial(n: num)
 print("\(num)! = \(result)")
