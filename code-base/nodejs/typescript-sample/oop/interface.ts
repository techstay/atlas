// interfaces

interface Point {
  x: number
  y: number
}

class Point2D implements Point {
  x: number
  y: number

  constructor(x: number, y: number) {
    this.x = x
    this.y = y
  }

}

const point = new Point2D(6, 4)
console.log(point)
