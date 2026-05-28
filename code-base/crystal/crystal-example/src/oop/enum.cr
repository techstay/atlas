enum TrafficLight
  Red
  Yellow
  Green

  def next
    case self
    when Red
      Yellow
    when Yellow
      Green
    when Green
      Red
    end
  end
end

p! TrafficLight::Red.next
