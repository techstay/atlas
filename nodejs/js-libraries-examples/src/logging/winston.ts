import winston from 'winston'

const logger = winston.createLogger({
  level: 'debug',
  format: winston.format.combine(
    winston.format.timestamp({
      format: 'YYYY-MM-DD HH:mm:ss',
    }),
    winston.format.colorize({ all: true }),
    winston.format.align(),
    winston.format.printf((info) => `${info.timestamp} | ${info.level} |${info.message}`),
  ),
  transports: [new winston.transports.Console()],
})

export default logger
