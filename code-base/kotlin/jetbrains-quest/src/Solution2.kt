package yitian.study

// https://twitter.com/jetbrains/status/1237694815283879943
fun twitterCode2() {
    val twitterCode =
        ".spleh A+lrtC/dmC .thgis fo tuo si ti semitemos ,etihw si txet nehw sa drah kooL .tseretni wohs dluohs uoy ecalp a si ,dessecorp si xat hctuD erehw esac ehT .sedih tseuq fo txen eht erehw si ,deificeps era segaugnal cificeps-niamod tcudorp ehT"
    println(twitterCode.reversed())
}

fun decryptCipher2() {
    val sss =
        "d1D j00 kN0w J378r41n2 12 4lW4Y2 H1R1N9? ch3CK 0u7 73h K4r33r2 P493 4nD 533 1f 7H3r3 12 4 J08 F0r J00 0R 4 KW357 cH4LL3n93 70 90 fUr7h3r @  l3457."
    val ddd =
        "Did you know Jetbrains is always hiring? Check our ten careers page and see if there is a job for you or a quest challenge to go further at least."
//    println(
//        sss.replace('j','y')
//            .replace("oo","ou")
//            .replace('0','o')
//            .replace('3','e')
//            .replace('7','t')
//            .replace('8','b')
//            .replace('4','a')
//            .replace('2','s')
//            .replace('1','i')
//            .replace('9','g')
//            .replace('K','c')
//    )
    println(ddd)
}

fun main() {
    twitterCode2()
    decryptCipher2()
}
