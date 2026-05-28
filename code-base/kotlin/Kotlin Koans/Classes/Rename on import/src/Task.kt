import java.util.Random as JRandom
import kotlin.random.Random as KRandom

fun useDifferentRandomClasses(): String {
    return "Kotlin random: " +
        KRandom.nextInt(2) +
        " Java random:" +
        JRandom().nextInt(2) +
        "."
}
