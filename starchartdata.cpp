#include "starchartdata.h"

const std::array<StarInfo, star_count>& getStarData()
{
    static const std::array<StarInfo, star_count> star_data = {{
        {"Achernar", 136, 175, 537.5, 272.9},
        {"Alcor", 240, 231, 970.8, 25.0},
        {"Aldebaran", 184, 156, 737.5, 356.2},
        {"Algol", 223, 163, 900.0, 325.0},
        {"Almagest", 245, 183, 990.9, 235.9},
        {"Altair", 115, 89, 450.0, 650.0},
        {"Alpha Andromedae", 214, 78, 862.5, 700.0},
        {"Beta Andromedae", 215, 75, 866.6, 710.4},
        {"Antares", 163, 65, 647.9, 754.1},
        {"Alpha Antliae", 71, 32, 268.7, 900.0},
        {"Beta Antliae", 72, 34, 270.6, 891.0},
        {"Gamma Antliae", 75, 36, 283.1, 885.4},
        {"Delta Antliae", 80, 36, 305.0, 883.3},
        {"Epsilon Antliae", 68, 34, 253.5, 891.7},
        {"Zeta Antliae", 69, 30, 258.1, 910.5},
        {"Alpha Apodis", 69, 43, 258.2, 850.7},
        {"Beta Apodis", 69, 42, 259.3, 856.9},
        {"Gamma Apodis", 68, 42, 256.2, 857.2},
        {"Delta Apodis", 68, 43, 253.6, 850.4},
        {"Alpha Aquarii", 213, 40, 856.0, 863.8},
        {"Beta Aquarii", 215, 39, 863.0, 869.3},
        {"Gamma Aquarii", 212, 37, 853.4, 879.7},
        {"Delta Aquarii", 213, 36, 858.8, 881.2},
        {"Epsilon Aquarii", 217, 40, 875.0, 864.5},
        {"Zeta Aquarii", 214, 42, 862.5, 856.2},
        {"Eta Aquarii", 211, 42, 849.2, 857.8},
        {"Alpha Aquilae", 227, 15, 915.9, 974.5},
        {"Beta Aquilae", 228, 15, 918.6, 974.1},
        {"Gamma Aquilae", 226, 15, 912.0, 974.1},
        {"Delta Aquilae", 227, 17, 914.4, 968.6},
        {"Epsilon Aquilae", 227, 14, 914.7, 979.0},
        {"Alpha Arae", 232, 217, 933.9, 84.3},
        {"Beta Arae", 231, 215, 933.3, 93.7},
        {"Gamma Arae", 234, 215, 941.9, 94.2},
        {"Delta Arae", 230, 219, 929.2, 75.0},
        {"Epsilon Arae", 229, 218, 923.7, 82.1},
        {"Arcturus", 239, 105, 964.5, 579.1},
        {"Alpha Arianni", 185, 197, 739.5, 175.0},
        {"Beta Arianni", 180, 195, 718.7, 183.3},
        {"Gamma Arianni", 185, 198, 739.5, 168.7},
        {"Alpha Arietis", 232, 201, 937.5, 158.3},
        {"Beta Arietis", 235, 201, 946.9, 154.8},
        {"Gamma Arietis", 235, 199, 947.7, 167.0},
        {"Delta Arietis", 236, 198, 954.1, 168.7},
        {"Epsilon Arietis", 237, 197, 955.9, 173.5},
        {"Alpha Aurigae", 201, 189, 806.2, 208.3},
        {"Beta Aurigae", 201, 191, 808.0, 201.1},
        {"Gamma Aurigae", 203, 191, 816.3, 200.9},
        {"Delta Aurigae", 204, 193, 818.7, 193.7},
        {"Bellatrix", 138, 193, 545.8, 191.6},
        {"Betelgeuse", 106, 151, 412.5, 377.0},
        {"Alpha Bootis", 12, 176, 22.9, 266.6},
        {"Beta Bootis", 15, 174, 35.1, 275.8},
        {"Gamma Bootis", 16, 171, 38.4, 290.0},
        {"Delta Bootis", 12, 180, 21.7, 250.9},
        {"Epsilon Bootis", 10, 175, 13.8, 269.6},
        {"Zeta Bootis", 11, 171, 16.7, 287.5},
        {"Eta Bootis", 23, 171, 67.2, 286.3},
        {"Alpha Brahe", 156, 184, 620.8, 233.3},
        {"Beta Brahe", 161, 184, 639.5, 231.2},
        {"Gamma Brahe", 160, 175, 635.4, 272.9},
        {"Delta Brahe", 162, 174, 645.8, 275.0},
        {"Epsilon Brahe", 161, 177, 641.6, 262.5},
        {"Zeta Brahe", 163, 181, 650.0, 245.8},
        {"Alpha Caeli", 65, 220, 241.1, 71.8},
        {"Beta Caeli", 69, 220, 258.9, 74.1},
        {"Gamma Caeli", 75, 219, 285.4, 78.7},
        {"Delta Caeli", 81, 219, 308.9, 78.2},
        {"Epsilon Caeli", 87, 218, 333.3, 80.1},
        {"Alpha Camelopardalis", 153, 145, 606.2, 404.1},
        {"Beta Camelopardalis", 150, 144, 595.8, 408.3},
        {"Gamma Camelopardalis", 154, 147, 612.5, 393.7},
        {"Delta Camelopardalis", 158, 149, 627.0, 383.3},
        {"Epsilon Camelopardalis", 150, 147, 593.7, 393.7},
        {"Zeta Camelopardalis", 155, 143, 616.6, 412.5},
        {"Eta Camelopardalis", 156, 140, 620.8, 422.9},
        {"Theta Camelopardalis", 149, 145, 589.5, 402.0},
        {"Iota Camelopardalis", 158, 147, 629.1, 393.7},
        {"Alpha Cancri", 126, 120, 493.7, 514.5},
        {"Beta Cancri", 131, 120, 515.5, 512.2},
        {"Gamma Cancri", 127, 123, 500.6, 501.1},
        {"Delta Cancri", 129, 125, 509.4, 493.1},
        {"Canopus", 59, 202, 218.7, 150.0},
        {"Capella", 109, 234, 424.4, 9.1},
        {"Alpha Capricorni", 78, 119, 297.9, 516.6},
        {"Beta Capricorni", 80, 119, 303.5, 517.8},
        {"Gamma Capricorni", 79, 116, 299.3, 531.8},
        {"Alpha Carinae", 94, 113, 362.5, 543.7},
        {"Beta Carinae", 89, 113, 341.6, 543.7},
        {"Gamma Carinae", 93, 112, 358.3, 547.9},
        {"Alpha Cassiopeiae", 92, 119, 354.1, 518.7},
        {"Beta Cassiopeiae", 97, 117, 377.0, 525.0},
        {"Gamma Cassiopeiae", 95, 121, 367.9, 506.8},
        {"Delta Cassiopeiae", 100, 120, 387.5, 514.5},
        {"Epsilon Cassiopeiae", 103, 119, 399.4, 518.5},
        {"Alpha Centauri", 44, 214, 155.9, 99.3},
        {"Beta Centauri", 41, 216, 141.2, 90.5},
        {"Gamma Centauri", 45, 211, 157.9, 111.5},
        {"Delta Centauri", 38, 208, 131.2, 126.0},
        {"Epsilon Centauri", 43, 217, 151.5, 86.6},
        {"Zeta Centauri", 42, 219, 146.3, 77.9},
        {"Alpha Cephei", 97, 104, 375.0, 583.3},
        {"Beta Cephei", 94, 106, 362.5, 575.0},
        {"Alpha Cerenkov", 108, 191, 422.1, 198.6},
        {"Beta Cerenkov", 115, 191, 450.0, 200.0},
        {"Alpha Ceti", 76, 135, 287.5, 447.9},
        {"Beta Ceti", 76, 145, 287.5, 404.1},
        {"Gamma Ceti", 80, 144, 303.8, 408.3},
        {"Delta Ceti", 77, 139, 293.7, 430.6},
        {"Epsilon Ceti", 72, 130, 270.8, 470.8},
        {"Zeta Ceti", 76, 130, 289.5, 468.7},
        {"Eta Ceti", 74, 140, 281.2, 425.0},
        {"Alpha Chamaeleonis", 126, 75, 497.1, 710.4},
        {"Beta Chamaeleonis", 126, 77, 495.5, 703.4},
        {"Gamma Chamaeleonis", 124, 77, 489.5, 704.1},
        {"Delta Chamaeleonis", 124, 75, 485.4, 712.5},
        {"Epsilon Chamaeleonis", 124, 73, 487.9, 720.1},
        {"Zeta Chamaeleonis", 126, 72, 495.8, 722.9},
        {"Eta Chamaeleonis", 129, 74, 508.3, 714.5},
        {"Theta Chamaeleonis", 131, 79, 514.5, 695.8},
        {"Iota Chamaeleonis", 131, 80, 514.5, 687.5},
        {"Kappa Chamaeleonis", 129, 83, 506.2, 675.0},
        {"Alpha Chandrasekhar", 10, 88, 12.5, 654.1},
        {"Beta Chandrasekhar", 16, 84, 37.5, 671.6},
        {"Gamma Chandrasekhar", 12, 86, 20.8, 662.5},
        {"Delta Chandrasekhar", 11, 88, 18.7, 652.0},
        {"Epsilon Chandrasekhar", 14, 84, 31.2, 672.8},
        {"Alpha Circini", 16, 101, 39.5, 597.9},
        {"Beta Circini", 15, 98, 36.5, 609.3},
        {"Gamma Circini", 17, 94, 43.7, 627.0},
        {"Delta Circini", 20, 97, 54.1, 614.5},
        {"Epsilon Circini", 20, 101, 56.3, 598.0},
        {"Zeta Circini", 18, 101, 45.6, 598.9},
        {"Alpha Columbae", 25, 90, 75.0, 645.8},
        {"Beta Columbae", 25, 87, 77.0, 660.2},
        {"Gamma Columbae", 24, 96, 72.9, 620.8},
        {"Alpha Copernicus", 146, 177, 579.1, 262.5},
        {"Beta Copernicus", 151, 177, 600.8, 263.1},
        {"Gamma Copernicus", 142, 179, 562.5, 252.0},
        {"Beta Corvi", 15, 14, 33.3, 981.2},
        {"Gamma Corvi", 8, 21, 6.2, 947.9},
        {"Delta Corvi", 31, 23, 100.0, 939.5},
        {"Epsilon Corvi", 9, 29, 10.4, 912.5},
        {"Zeta Corvi", 9, 10, 8.3, 997.9},
        {"Eta Corvi", 31, 11, 102.0, 993.7},
        {"Alpha Crateris", 151, 109, 601.4, 563.2},
        {"Beta Crateris", 154, 105, 610.7, 578.5},
        {"Gamma Crateris", 155, 100, 616.6, 600.0},
        {"Delta Crateris", 156, 102, 620.0, 593.5},
        {"Epsilon Crateris", 158, 103, 630.1, 587.5},
        {"Zeta Crateris", 163, 100, 649.6, 603.2},
        {"Eta Crateris", 161, 101, 642.9, 595.8},
        {"Theta Crateris", 156, 94, 621.5, 625.5},
        {"Alpha Crucis", 141, 94, 558.3, 629.1},
        {"Beta Crucis", 139, 85, 547.9, 668.7},
        {"Gamma Crucis", 133, 95, 525.0, 622.9},
        {"Delta Crucis", 138, 102, 543.7, 591.6},
        {"Alpha Cygnus", 18, 132, 47.9, 458.3},
        {"Beta Cygnus", 18, 131, 47.9, 464.5},
        {"Gamma Cygnus", 20, 130, 56.2, 470.8},
        {"Delta Cygnus", 17, 129, 41.6, 471.7},
        {"Epsilon Cygnus", 13, 132, 25.0, 458.3},
        {"Alpha Delphini", 96, 90, 371.6, 645.8},
        {"Beta Delphini", 97, 89, 377.0, 650.0},
        {"Deneb", 59, 235, 218.7, 8.3},
        {"Alpha Doradus", 108, 81, 420.8, 685.4},
        {"Beta Doradus", 110, 79, 429.1, 693.7},
        {"Alpha Draconis", 73, 47, 277.1, 835.1},
        {"Beta Draconis", 75, 46, 282.2, 839.5},
        {"Gamma Draconis", 67, 54, 251.8, 805.6},
        {"Delta Draconis", 68, 47, 253.5, 835.8},
        {"Epsilon Draconis", 75, 58, 283.6, 785.7},
        {"Zeta Draconis", 73, 40, 277.6, 867.3},
        {"Eta Draconis", 82, 46, 315.1, 839.0},
        {"Theta Draconis", 85, 55, 327.0, 800.0},
        {"Iota Draconis", 92, 49, 356.2, 825.0},
        {"Kappa Draconis", 66, 40, 245.8, 866.6},
        {"Lambda Draconis", 63, 46, 236.2, 839.5},
        {"Mu Draconis", 62, 39, 231.0, 870.2},
        {"Nu Draconis", 62, 35, 230.0, 886.1},
        {"Xi Draconis", 69, 40, 258.8, 865.3},
        {"Alpha Equulei", 149, 86, 591.0, 662.4},
        {"Beta Equulei", 152, 84, 602.0, 672.9},
        {"Alpha Eridani", 148, 61, 587.5, 772.9},
        {"Beta Eridani", 150, 63, 595.8, 764.5},
        {"Gamma Eridani", 146, 64, 579.1, 758.3},
        {"Fomalhaut", 112, 42, 437.5, 856.2},
        {"Alpha Fornacis", 136, 58, 537.5, 787.5},
        {"Beta Fornacis", 143, 54, 564.5, 802.0},
        {"Gamma Fornacis", 148, 53, 587.5, 806.2},
        {"Delta Fornacis", 151, 55, 597.9, 797.9},
        {"Epsilon Fornacis", 152, 57, 604.1, 791.6},
        {"Zeta Fornacis", 154, 55, 610.4, 800.0},
        {"Eta Fornacis", 156, 58, 618.7, 787.5},
        {"Alpha Geminorum", 126, 60, 495.8, 779.1},
        {"Beta Geminorum", 127, 60, 497.9, 779.1},
        {"Gamma Geminorum", 124, 67, 489.5, 745.8},
        {"Delta Geminorum", 118, 67, 464.5, 747.9},
        {"Alpha Giclas", 27, 228, 84.3, 38.0},
        {"Beta Giclas", 27, 227, 84.3, 43.1},
        {"Gamma Giclas", 26, 229, 80.3, 33.7},
        {"Delta Giclas", 28, 229, 87.7, 34.0},
        {"Epsilon Giclas", 30, 226, 95.8, 46.8},
        {"Zeta Giclas", 33, 229, 111.6, 33.4},
        {"Eta Giclas", 24, 236, 70.8, 4.1},
        {"Theta Giclas", 23, 220, 67.5, 74.2},
        {"Alpha Gorno", 73, 233, 277.1, 14.6},
        {"Beta Gorno", 74, 234, 281.4, 8.9},
        {"Gamma Gorno", 77, 234, 293.9, 11.6},
        {"Delta Gorno", 77, 230, 290.8, 26.9},
        {"Epsilon Gorno", 74, 230, 282.0, 30.1},
        {"Groombridge", 247, 31, 996.0, 904.2},
        {"Alpha Gruis", 61, 153, 227.4, 366.3},
        {"Beta Gruis", 58, 156, 214.8, 355.1},
        {"Gamma Gruis", 61, 152, 225.0, 370.8},
        {"Delta Gruis", 63, 152, 235.4, 374.1},
        {"Epsilon Gruis", 65, 153, 241.6, 368.7},
        {"Zeta Gruis", 69, 151, 258.3, 375.0},
        {"Eta Gruis", 66, 147, 247.9, 395.8},
        {"Alpha Herculis", 45, 154, 160.4, 364.5},
        {"Beta Herculis", 49, 159, 175.8, 341.8},
        {"Alpha Horologii", 180, 65, 720.8, 754.1},
        {"Beta Horologii", 178, 72, 712.5, 725.0},
        {"Gamma Horologii", 180, 78, 720.8, 700.0},
        {"Delta Horologii", 184, 73, 736.0, 718.4},
        {"Epsilon Horologii", 188, 72, 753.2, 725.8},
        {"Zeta Horologii", 186, 65, 744.3, 753.8},
        {"Eta Horologii", 185, 58, 739.5, 785.4},
        {"Theta Horologii", 180, 58, 720.0, 784.9},
        {"Iota Horologii", 177, 55, 708.3, 799.3},
        {"Kappa Horologii", 173, 59, 688.9, 780.3},
        {"Lambda Horologii", 174, 66, 694.0, 751.4},
        {"Alpha Hyades", 207, 34, 832.2, 893.4},
        {"Beta Hyades", 208, 33, 837.5, 895.8},
        {"Gamma Hyades", 208, 31, 837.5, 904.1},
        {"Delta Hyades", 205, 33, 824.9, 895.8},
        {"Epsilon Hyades", 211, 29, 850.0, 912.5},
        {"Zeta Hyades", 211, 24, 850.0, 937.2},
        {"Eta Hyades", 210, 23, 845.8, 939.3},
        {"Theta Hyades", 206, 20, 829.6, 954.8},
        {"Iota Hyades", 199, 21, 800.0, 950.5},
        {"Kappa Hyades", 191, 19, 766.4, 958.9},
        {"Lambda Hyades", 181, 24, 725.5, 937.4},
        {"Alpha Hydrae", 183, 89, 733.3, 650.0},
        {"Beta Hydrae", 195, 88, 781.2, 656.2},
        {"Gamma Hydrae", 203, 95, 816.6, 625.0},
        {"Alpha Hyginus", 212, 142, 852.0, 416.6},
        {"Beta Hyginus", 215, 144, 864.5, 406.2},
        {"Hyperion", 165, 208, 656.2, 127.0},
        {"Alpha Illuminati", 63, 162, 235.4, 329.1},
        {"Beta Illuminati", 67, 158, 252.0, 343.7},
        {"Gamma Illuminati", 71, 161, 268.7, 333.3},
        {"Delta Illuminati", 63, 165, 235.4, 316.6},
        {"Epsilon Illuminati", 72, 169, 272.7, 295.1},
        {"Zeta Illuminati", 66, 174, 245.8, 275.0},
        {"Eta Illuminati", 60, 172, 220.8, 285.4},
        {"Theta Illuminati", 55, 167, 201.1, 304.3},
        {"Alpha Indi", 103, 206, 400.0, 136.3},
        {"Beta Indi", 102, 206, 395.8, 135.4},
        {"Alpha Kepler", 147, 164, 581.2, 320.8},
        {"Beta Kepler", 142, 169, 562.5, 295.8},
        {"Gamma Kepler", 152, 169, 602.0, 297.9},
        {"Alpha Klystron", 53, 10, 193.7, 997.9},
        {"Beta Klystron", 77, 20, 291.6, 954.1},
        {"Alpha Krueger", 14, 226, 30.4, 47.7},
        {"Beta Krueger", 19, 226, 53.0, 44.2},
        {"Gamma Krueger", 19, 225, 52.2, 52.5},
        {"Delta Krueger", 20, 230, 57.0, 28.9},
        {"Epsilon Krueger", 13, 233, 26.5, 15.6},
        {"Zeta Krueger", 10, 224, 13.4, 56.5},
        {"Alpha Lacaille", 10, 215, 14.6, 95.5},
        {"Beta Lacaille", 12, 215, 23.0, 95.2},
        {"Gamma Lacaille", 12, 217, 24.2, 85.7},
        {"Alpha Lacertae", 209, 53, 841.6, 808.3},
        {"Beta Lacertae", 205, 54, 822.9, 804.1},
        {"Alpha Lalande", 91, 176, 349.9, 264.8},
        {"Beta Lalande", 88, 173, 340.0, 280.4},
        {"Gamma Lalande", 94, 172, 361.9, 283.0},
        {"Delta Lalande", 97, 173, 375.9, 277.8},
        {"Alpha Lentilis", 118, 100, 462.5, 600.0},
        {"Beta Lentilis", 118, 103, 462.5, 589.5},
        {"Gamma Lentilis", 117, 99, 458.3, 604.1},
        {"Delta Lentilis", 120, 101, 472.9, 595.8},
        {"Alpha Leonis", 223, 50, 900.0, 822.9},
        {"Beta Leonis", 234, 58, 943.7, 785.4},
        {"Gamma Leonis", 240, 70, 968.7, 733.3},
        {"Alpha Leporis", 201, 42, 807.3, 858.8},
        {"Beta Leporis", 191, 40, 766.6, 866.6},
        {"Gamma Leporis", 180, 36, 718.7, 881.2},
        {"Alpha Librae", 184, 31, 735.4, 906.2},
        {"Beta Librae", 185, 29, 741.4, 912.4},
        {"Gamma Librae", 188, 30, 754.5, 910.7},
        {"Delta Librae", 194, 28, 779.1, 918.7},
        {"Epsilon Librae", 194, 27, 779.1, 922.9},
        {"Zeta Librae", 195, 30, 783.3, 908.3},
        {"Eta Librae", 197, 28, 788.9, 918.1},
        {"Alpha Lipi", 141, 40, 556.2, 864.5},
        {"Beta Lipi", 139, 46, 550.0, 839.5},
        {"Gamma Lipi", 138, 36, 547.5, 882.3},
        {"Delta Lipi", 143, 33, 564.5, 897.9},
        {"Epsilon Lipi", 138, 49, 543.7, 827.0},
        {"Alpha Luyten", 109, 199, 425.0, 164.5},
        {"Beta Luyten", 111, 198, 433.3, 168.7},
        {"Gamma Luyten", 111, 201, 433.3, 156.2},
        {"Alpha Lyncis", 141, 20, 560.0, 955.2},
        {"Beta Lyncis", 144, 21, 571.1, 947.5},
        {"Gamma Lyncis", 146, 16, 578.1, 971.1},
        {"Delta Lyncis", 144, 14, 570.4, 979.5},
        {"Epsilon Lyncis", 135, 20, 532.9, 953.8},
        {"Zeta Lyncis", 133, 16, 522.9, 972.9},
        {"Eta Lyncis", 151, 21, 598.9, 949.6},
        {"Theta Lyncis", 154, 18, 612.5, 960.4},
        {"Alpha Lyrae", 53, 208, 191.6, 127.0},
        {"Beta Lyrae", 52, 213, 189.5, 104.1},
        {"Alpha Maksutov", 151, 117, 597.7, 524.6},
        {"Beta Maksutov", 158, 112, 627.0, 547.9},
        {"Menkar", 122, 26, 481.2, 927.0},
        {"Alpha Mensae", 99, 164, 383.3, 318.7},
        {"Beta Mensae", 104, 171, 403.0, 288.7},
        {"Gamma Mensae", 118, 169, 464.5, 295.8},
        {"Alpha Mersenne", 69, 86, 260.4, 664.5},
        {"Beta Mersenne", 65, 71, 241.6, 729.1},
        {"Metis", 144, 132, 570.8, 460.4},
        {"Microscopii", 112, 10, 439.5, 997.9},
        {"Alpha Mira", 92, 184, 355.1, 232.0},
        {"Beta Mira", 95, 193, 367.8, 192.6},
        {"Gamma Mira", 100, 185, 388.4, 226.2},
        {"Delta Mira", 87, 183, 335.4, 235.4},
        {"Mizar", 17, 207, 41.6, 130.1},
        {"Alpha Monocerotis", 100, 73, 387.5, 718.7},
        {"Beta Monocerotis", 99, 71, 385.4, 729.1},
        {"Alpha Muscae", 34, 60, 112.5, 779.1},
        {"Beta Muscae", 32, 62, 104.1, 770.8},
        {"Gamma Muscae", 31, 73, 102.0, 718.7},
        {"Delta Muscae", 40, 54, 139.5, 804.1},
        {"Epsilon Muscae", 43, 47, 152.0, 833.3},
        {"Zeta Muscae", 34, 42, 112.5, 858.3},
        {"Alpha Normae", 41, 114, 142.5, 540.4},
        {"Beta Normae", 41, 116, 141.6, 531.5},
        {"Gamma Normae", 43, 117, 152.0, 526.1},
        {"Delta Normae", 45, 117, 161.3, 527.9},
        {"Epsilon Normae", 51, 114, 185.4, 541.6},
        {"Zeta Normae", 59, 109, 215.9, 561.4},
        {"Alpha Octantis", 45, 85, 157.8, 666.8},
        {"Beta Octantis", 39, 89, 136.0, 648.9},
        {"Alpha Olber", 13, 187, 27.0, 218.7},
        {"Beta Olber", 10, 186, 12.5, 222.9},
        {"Gamma Olber", 14, 185, 31.2, 225.0},
        {"Alpha Ophiuchi", 17, 37, 43.7, 877.0},
        {"Beta Ophiuchi", 18, 35, 47.9, 887.5},
        {"Gamma Ophiuchi", 15, 34, 33.3, 891.6},
        {"Organon", 172, 223, 685.8, 57.7},
        {"Alpha Orionis", 52, 99, 190.2, 606.5},
        {"Beta Orionis", 54, 101, 197.8, 596.8},
        {"Gamma Orionis", 53, 103, 192.3, 587.8},
        {"Delta Orionis", 48, 102, 171.4, 592.6},
        {"Epsilon Orionis", 44, 104, 154.5, 581.8},
        {"Zeta Orionis", 44, 99, 155.8, 605.8},
        {"Eta Orionis", 50, 93, 179.5, 632.9},
        {"Theta Orionis", 52, 93, 188.1, 630.8},
        {"Iota Orionis", 58, 92, 211.8, 637.9},
        {"Kappa Orionis", 60, 96, 220.0, 617.6},
        {"Lambda Orionis", 59, 99, 215.9, 607.3},
        {"Mu Orionis", 60, 99, 222.8, 603.8},
        {"Alpha Pavonis", 20, 55, 56.2, 800.0},
        {"Beta Pavonis", 23, 55, 68.7, 800.0},
        {"Alpha Pegasi", 15, 63, 33.3, 762.5},
        {"Beta Pegasi", 16, 67, 39.5, 745.8},
        {"Alpha Persei", 230, 178, 929.1, 258.3},
        {"Beta Persei", 235, 176, 947.9, 266.6},
        {"Gamma Persei", 231, 173, 933.3, 279.1},
        {"Delta Persei", 229, 172, 925.0, 285.4},
        {"Epsilon Persei", 224, 182, 903.8, 240.7},
        {"Zeta Persei", 235, 173, 946.9, 280.6},
        {"Eta Persei", 221, 175, 889.5, 268.7},
        {"Theta Persei", 232, 182, 937.5, 241.6},
        {"Iota Persei", 220, 184, 887.5, 231.2},
        {"Alpha Phoenicis", 233, 137, 941.6, 439.5},
        {"Beta Phoenicis", 237, 142, 957.3, 418.2},
        {"Gamma Phoenicis", 243, 142, 981.2, 414.5},
        {"Alpha Pictoris", 231, 152, 933.3, 370.8},
        {"Beta Pictoris", 231, 156, 931.2, 356.2},
        {"Gamma Pictoris", 232, 155, 937.5, 360.4},
        {"Delta Pictoris", 238, 155, 959.9, 358.3},
        {"Alpha Piscium", 210, 158, 843.7, 345.8},
        {"Beta Piscium", 218, 156, 879.1, 354.1},
        {"Gamma Piscium", 216, 154, 870.8, 362.5},
        {"Delta Piscium", 218, 158, 877.0, 345.8},
        {"Pollux", 143, 234, 565.2, 9.8},
        {"Procyon", 24, 185, 74.2, 226.8},
        {"Alpha Ptolemae", 55, 226, 200.4, 44.1},
        {"Beta Ptolemae", 56, 226, 205.8, 47.5},
        {"Gamma Ptolemae", 57, 224, 210.0, 55.4},
        {"Delta Ptolemae", 58, 226, 215.6, 44.0},
        {"Epsilon Ptolemae", 51, 230, 185.5, 27.0},
        {"Zeta Ptolemae", 50, 229, 178.7, 33.8},
        {"Eta Ptolemae", 48, 227, 174.0, 42.3},
        {"Alpha Puppis", 202, 166, 812.5, 308.3},
        {"Beta Puppis", 206, 169, 829.1, 297.9},
        {"Gamma Puppis", 206, 169, 827.0, 295.8},
        {"Alpha Pyxidis", 222, 123, 895.8, 500.0},
        {"Beta Pyxidis", 223, 123, 900.0, 500.0},
        {"Gamma Pyxidis", 225, 121, 906.2, 508.3},
        {"Alpha Raynet", 75, 198, 284.0, 167.6},
        {"Beta Raynet", 76, 200, 288.1, 161.4},
        {"Gamma Raynet", 74, 193, 279.1, 189.5},
        {"Regulus", 96, 212, 373.2, 106.7},
        {"Alpha Reticuli", 183, 122, 731.2, 506.2},
        {"Beta Reticuli", 176, 116, 702.0, 529.1},
        {"Gamma Reticuli", 185, 121, 741.6, 508.3},
        {"Delta Reticuli", 181, 132, 725.0, 458.3},
        {"Rigel", 57, 189, 210.4, 208.3},
        {"Alpha Sagittae", 13, 107, 25.0, 568.7},
        {"Beta Sagittae", 15, 105, 37.1, 577.2},
        {"Gamma Sagittae", 10, 103, 15.2, 590.0},
        {"Alpha Sagittarii", 171, 191, 683.3, 200.0},
        {"Beta Sagittarii", 176, 182, 702.0, 239.5},
        {"Gamma Sagittarii", 177, 174, 708.3, 277.0},
        {"Delta Sagittarii", 165, 168, 656.2, 302.0},
        {"Alpha Saurus", 62, 185, 230.6, 228.5},
        {"Beta Saurus", 64, 184, 240.2, 230.9},
        {"Gamma Saurus", 62, 182, 229.8, 238.5},
        {"Alpha Scorpii", 162, 194, 646.7, 187.8},
        {"Beta Scorpii", 163, 193, 650.0, 191.6},
        {"Gamma Scorpii", 163, 190, 647.9, 206.2},
        {"Delta Scorpii", 152, 190, 603.6, 203.5},
        {"Epsilon Scorpii", 158, 186, 629.1, 220.8},
        {"Zeta Scorpii", 163, 186, 650.0, 220.8},
        {"Alpha Sculptoris", 152, 201, 604.1, 156.2},
        {"Gamma Sculptoris", 153, 200, 608.3, 162.5},
        {"Delta Sculptoris", 147, 209, 581.2, 120.8},
        {"Epsilon Sculptoris", 144, 202, 570.8, 152.0},
        {"Alpha Scuti", 128, 228, 503.9, 37.3},
        {"Beta Scuti", 127, 223, 501.4, 58.4},
        {"Gamma Scuti", 133, 223, 525.6, 60.8},
        {"Delta Scuti", 131, 230, 516.0, 28.0},
        {"Epsilon Scuti", 135, 228, 533.8, 35.5},
        {"Zeta Scuti", 135, 233, 531.3, 15.0},
        {"Alpha Serpentis", 125, 232, 491.1, 18.0},
        {"Beta Serpentis", 124, 231, 486.1, 26.2},
        {"Gamma Serpentis", 125, 230, 492.3, 29.4},
        {"Delta Serpentis", 121, 231, 474.7, 22.1},
        {"Epsilon Serpentis", 124, 227, 487.2, 40.8},
        {"Zeta Serpentis", 127, 236, 500.7, 3.5},
        {"Eta Serpentis", 120, 235, 471.4, 7.8},
        {"Theta Serpentis", 116, 233, 452.9, 16.9},
        {"Iota Serpentis", 117, 227, 459.6, 42.9},
        {"Alpha Sextantis", 111, 212, 433.7, 106.6},
        {"Beta Sextantis", 117, 210, 460.4, 118.7},
        {"Gamma Sextantis", 124, 210, 487.5, 114.5},
        {"Delta Sextantis", 124, 214, 487.3, 96.8},
        {"Epsilon Sextantis", 121, 216, 477.0, 89.5},
        {"Zeta Sextantis", 119, 216, 468.1, 91.6},
        {"Sirius", 50, 202, 180.6, 150.7},
        {"Sol", 49, 204, 175.2, 145.0},
        {"Alpha Squidi", 58, 148, 214.5, 391.6},
        {"Beta Squidi", 56, 146, 206.2, 399.1},
        {"Gamma Squidi", 58, 141, 214.5, 420.8},
        {"Alpha Tauri", 12, 153, 22.9, 366.6},
        {"Beta Tauri", 13, 152, 28.8, 373.5},
        {"Gamma Tauri", 13, 154, 26.7, 364.5},
        {"Delta Tauri", 11, 151, 16.6, 377.0},
        {"Epsilon Tauri", 10, 157, 14.9, 351.9},
        {"Zeta Tauri", 9, 154, 9.0, 361.4},
        {"Alpha Telescopii", 13, 145, 28.5, 402.0},
        {"Beta Telescopii", 14, 143, 29.1, 410.4},
        {"Gamma Telescopii", 19, 141, 50.0, 418.7},
        {"Alpha Trianguli", 198, 229, 793.4, 31.8},
        {"Beta Trianguli", 198, 230, 795.8, 27.0},
        {"Gamma Trianguli", 201, 229, 806.2, 31.8},
        {"Alpha Tucanae", 103, 113, 400.0, 543.7},
        {"Beta Tucanae", 101, 109, 393.7, 562.5},
        {"Gamma Tucanae", 105, 111, 408.3, 551.3},
        {"Vega", 15, 15, 33.3, 975.0},
        {"Vela", 87, 193, 334.5, 193.1},
        {"Alpha Velorum", 27, 144, 86.0, 406.5},
        {"Beta Velorum", 29, 146, 92.6, 397.2},
        {"Alpha Virginis", 14, 163, 29.1, 325.0},
        {"Beta Virginis", 19, 162, 50.1, 325.9},
        {"Gamma Virginis", 26, 162, 79.1, 327.0},
        {"Delta Virginis", 33, 161, 110.4, 333.3},
        {"Alpha Vitalis", 79, 157, 300.0, 350.0},
        {"Beta Vitalis", 83, 160, 318.7, 337.5},
        {"Gamma Vitalis", 81, 153, 308.3, 367.4},
        {"Delta Vitalis", 73, 154, 277.0, 362.5},
        {"Alpha Volantis", 29, 196, 95.1, 177.0},
        {"Beta Volantis", 34, 195, 114.0, 184.7},
        {"Gamma Volantis", 32, 193, 104.8, 191.9},
        {"Delta Volantis", 30, 192, 97.7, 195.3},
        {"Epsilon Volantis", 24, 195, 70.5, 183.8},
        {"Zeta Volantis", 24, 197, 73.6, 173.7},
        {"Eta Volantis", 22, 199, 65.0, 164.6},
        {"Alpha Vulpeculae", 95, 178, 365.4, 258.7},
        {"Beta Vulpeculae", 94, 179, 364.1, 251.2},
        {"Gamma Vulpeculae", 96, 179, 371.3, 253.7},
        {"Delta Vulpeculae", 96, 177, 372.1, 261.9},
        {"Epsilon Vulpeculae", 95, 176, 366.8, 266.6},
        {"Zeta Vulpeculae", 93, 177, 360.8, 263.7},
        {"Eta Vulpeculae", 93, 178, 358.7, 256.6},
        {"Alpha Wolf", 45, 197, 160.1, 174.6},
        {"Beta Wolf", 47, 195, 166.6, 181.2},
        {"Zeeman", 87, 192, 335.2, 194.0},
        {"Unknown", 17, 92, 43.8, 637.2}
    }};

    return star_data;
}
