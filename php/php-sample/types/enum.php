<?php

enum TrafficLight
{
  case RED;
  case GREEN;
  case YELLOW;
}

var_dump(TrafficLight::cases());
