//#pragma once
#include <gtest/gtest.h>
#include <iostream>
#include "characterFactory.h"
//#include "JOURNEY_ACROSS_THE_MNT.cpp"

//2 unit tests for every concrete class (Binarion, Dataweaver, Technomancer,Generator)

    
    
    TEST(BINARION,checkDefualtAC)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");

            EXPECT_EQ(binarionTest->getAC(),7);
        }

    TEST(BINARION,checkModifiedAC)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");

            binarionTest->changeAC(20);
            EXPECT_EQ(binarionTest->getAC(),12);
        }
        
    TEST(BINARION, bitTwistTest) //attacks enemy
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");

            binarionTest->selectAction(1, testDummy, true);

            EXPECT_EQ(testDummy->getHP(), 0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

    TEST(BINARION, binaryShiftTest)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");
            

            binarionTest->selectAction(2, testDummy, true);

            EXPECT_EQ(testDummy->getHP(), 0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

    TEST(BINARION, codeFluxTest)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");
            
            binarionTest->selectAction(3, testDummy, true);
            EXPECT_FALSE(testDummy->isDefeated());
        }
    
    TEST(BINARION, healingPulseTest)
        {
            std::shared_ptr<Profession> binarionTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Theodore The Terrorizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");
            
            testDummy->changeHP(-3);
            binarionTest->selectAction(4, testDummy, true);

            EXPECT_EQ(testDummy->getHP(), 10);
            EXPECT_FALSE(testDummy->isDefeated());
        }

    TEST(GENERATOR,checkDefaultAC)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");

            EXPECT_EQ(generatorTest->getAC(),5);
        }

    TEST(GENERATOR,checkModifiedAC)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");

            generatorTest->changeAC(20);
            EXPECT_EQ(generatorTest->getAC(),12);
        }

    TEST(GENERATOR, generateEnergyTest)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");

            generatorTest->selectAction(1, generatorTest, true);

            EXPECT_EQ(generatorTest->getEnergy(), 5);
        }
    
    TEST(GENERATOR, shieldTest)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");

            generatorTest->selectAction(2, testDummy, true);

            EXPECT_EQ(testDummy->getAC(), 12);
        }

    TEST(GENERATOR, attackTest)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");

            generatorTest->selectAction(3, testDummy, true);

            EXPECT_EQ(testDummy->getHP(), 0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

    TEST(GENERATOR, healTest)
        {
            std::shared_ptr<Profession> generatorTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, CharacterFactory::GeneratorType, "Andrew The Antagonizer");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::BinarionType, "Billy");

            generatorTest->selectAction(4, testDummy, true);

            EXPECT_EQ(testDummy->getHP(), 10);
        }

    TEST(TECHNOMANCER,checkDefaultHP)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            EXPECT_EQ(technomancerTest->getHP(),80);
        }

    TEST(TECHNOMANCER,checkModifiedHP)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            technomancerTest->changeHP(-3);
            EXPECT_EQ(technomancerTest->getHP(),77);
        }

    TEST(TECHNOMANCER,ShockPunchTest)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::GeneratorType, "Billy");

            technomancerTest->selectAction(1, testDummy, true);
            EXPECT_EQ(testDummy->getHP(), 2);
            EXPECT_FALSE(testDummy->isDefeated());
        }

    TEST(TECHNOMANCER, hijackTest)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::GeneratorType, "Billy");

            technomancerTest->selectAction(2, testDummy, true);
            EXPECT_FALSE(testDummy->isDefeated());
        }

    TEST(TECHNOMANCER, systemLockTest)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::GeneratorType, "Billy");

            technomancerTest->selectAction(3, testDummy, true);
            EXPECT_FALSE(testDummy->isDefeated());
        }

    TEST(TECHNOMANCER, OverHeatTest)
        {
            std::shared_ptr<Profession> technomancerTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, CharacterFactory::TechnomancerType, "Randy The Radiator");

            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::GeneratorType, "Billy");

            technomancerTest->selectAction(4, testDummy, true);
            EXPECT_EQ(testDummy->getHP(), 2);
            EXPECT_FALSE(testDummy->isDefeated());
        }
    
    TEST(DATAWEAVER,checkDefaultHP)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");

            EXPECT_EQ(dataweaverTest->getHP(),50);

        }

    TEST(DATAWEAVER,checkModifiedHP)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");

            dataweaverTest->changeHP(-3);
            EXPECT_EQ(dataweaverTest->getHP(),47);
        }


    TEST(DATAWEAVER, quickAttackTest)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            dataweaverTest->selectAction(1, testDummy, true);
            EXPECT_EQ(testDummy->getHP(),0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

    TEST(DATAWEAVER, dataCorruptionTest)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            dataweaverTest->selectAction(2, testDummy, true);
            EXPECT_FALSE(testDummy->isDefeated());
        }

    TEST(DATAWEAVER, dataTransferTest)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");

            dataweaverTest->selectAction(3, dataweaverTest, true);
            EXPECT_EQ(dataweaverTest->getAC(),12);
        }
    TEST(DATAWEAVER, decryptTest)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, CharacterFactory::DataweaverType, "Miles The Maleficent");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            dataweaverTest->selectAction(4, testDummy, true);
            EXPECT_EQ(testDummy->getAC(),0);
            EXPECT_FALSE(testDummy->isDefeated());
        }

    TEST(FINALBOSS, attack1Test)
        {
            std::shared_ptr<Profession> finalBossTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::finalBoss_majorType, CharacterFactory::finalBoss_professionType, "Miles The Maleficent");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            finalBossTest->selectAction(1, testDummy, true);
            EXPECT_EQ(testDummy->getHP(),0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

    TEST(FINALBOSS, attack2Test)
        {
            std::shared_ptr<Profession> finalBossTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::finalBoss_majorType, CharacterFactory::finalBoss_professionType, "Miles The Maleficent");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            finalBossTest->selectAction(2, testDummy, true);
            EXPECT_EQ(testDummy->getAC(),0);
            EXPECT_FALSE(testDummy->isDefeated());
        }
    TEST(FINALBOSS, attack3Test)
        {
            std::shared_ptr<Profession> finalBossTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::finalBoss_majorType, CharacterFactory::finalBoss_professionType, "Miles The Maleficent");
            
            finalBossTest->selectAction(3, finalBossTest, true);
            EXPECT_EQ(finalBossTest->getHP(),250);
            EXPECT_FALSE(finalBossTest->isDefeated());
        }
    TEST(FINALBOSS, attack4Test)
        {
            std::shared_ptr<Profession> dataweaverTest = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::finalBoss_majorType, CharacterFactory::finalBoss_professionType, "Miles The Maleficent");
            std::shared_ptr<Profession> testDummy = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, CharacterFactory::TechnomancerType, "Billy");

            dataweaverTest->selectAction(4, testDummy, true);
            EXPECT_EQ(testDummy->getHP(),0);
            EXPECT_TRUE(testDummy->isDefeated());
        }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}