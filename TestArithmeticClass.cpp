#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
007
#include <cppunit/extensions/HelperMacros.h>
008
#include <cppunit/extensions/TestFactoryRegistry.h>
009
#include <cppunit/TestResult.h>
010
#include <cppunit/TestResultCollector.h>
011
#include <cppunit/TestRunner.h>
012
#include <cppunit/BriefTestProgressListener.h>
013
#include <cppunit/CompilerOutputter.h>
014
#include <cppunit/XmlOutputter.h>
015
#include <netinet/in.h>
016
 
017
#include "CBasicMath.hpp"
018
 
019
using namespace CppUnit;
020
using namespace std;
021
 
022
//-----------------------------------------------------------------------------
//023
// 
// 024
// class TestBasicMath : public CppUnit::TestFixture
// 025
// {
// 026
//     CPPUNIT_TEST_SUITE(TestBasicMath);
//     027
//         CPPUNIT_TEST(testAddition);
//         028
//             CPPUNIT_TEST(testMultiply);
//             029
//                 CPPUNIT_TEST_SUITE_END();
//                 030
//                  
//                  031
//                  public:
//                  032
//                      void setUp(void);
//                      033
//                          void tearDown(void);
//                          034
//                           
//                           035
//                           protected:
//                           036
//                               void testAddition(void);
//                               037
//                                   void testMultiply(void);
//                                   038
//                                    
//                                    039
//                                    private:
//                                    040
//                                     
//                                     041
//                                         CBasicMath *mTestObj;
//                                         042
//                                         };
//                                         043
//                                          
//                                          044
//                                          //-----------------------------------------------------------------------------
//                                          045
//                                           
//                                           046
//                                           void
//                                           047
//                                           TestBasicMath::testAddition(void)
//                                           048
//                                           {
//                                           049
//                                               CPPUNIT_ASSERT(5 == mTestObj->Addition(2,3));
//                                               050
//                                               }
//                                               051
//                                                
//                                                052
//                                                void
//                                                053
//                                                TestBasicMath::testMultiply(void)
//                                                054
//                                                {
//                                                055
//                                                    CPPUNIT_ASSERT(6 == mTestObj->Multiply(2,3));
//                                                    056
//                                                    }
//                                                    057
//                                                     
//                                                     058
//                                                     void TestBasicMath::setUp(void)
//                                                     059
//                                                     {
//                                                     060
//                                                         mTestObj = new CBasicMath();
//                                                         061
//                                                         }
//                                                         062
//                                                          
//                                                          063
//                                                          void TestBasicMath::tearDown(void)
//                                                          064
//                                                          {
//                                                          065
//                                                              delete mTestObj;
//                                                              066
//                                                              }
//                                                              067
//                                                               
//                                                               068
//                                                               //-----------------------------------------------------------------------------
//                                                               069
//                                                                
//                                                                070
//                                                                CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );
//                                                                071
//                                                                 
//                                                                 072
//                                                                 int main(int argc, char* argv[])
//                                                                 073
//                                                                 {
//                                                                 074
//                                                                     // informs test-listener about testresults
//                                                                     075
//                                                                         CPPUNIT_NS::TestResult testresult;
//                                                                         076
//                                                                          
//                                                                          077
//                                                                              // register listener for collecting the test-results
//                                                                              078
//                                                                                  CPPUNIT_NS::TestResultCollector collectedresults;
//                                                                                  079
//                                                                                      testresult.addListener (&collectedresults);
//                                                                                      080
//                                                                                       
//                                                                                       081
//                                                                                           // register listener for per-test progress output
//                                                                                           082
//                                                                                               CPPUNIT_NS::BriefTestProgressListener progress;
//                                                                                               083
//                                                                                                   testresult.addListener (&progress);
//                                                                                                   084
//                                                                                                    
//                                                                                                    085
//                                                                                                        // insert test-suite at test-runner by registry
//                                                                                                        086
//                                                                                                            CPPUNIT_NS::TestRunner testrunner;
//                                                                                                            087
//                                                                                                                testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
//                                                                                                                088
//                                                                                                                    testrunner.run(testresult);
//                                                                                                                    089
//                                                                                                                     
//                                                                                                                     090
//                                                                                                                         // output results in compiler-format
//                                                                                                                         091
//                                                                                                                             CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
//                                                                                                                             092
//                                                                                                                                 compileroutputter.write ();
//                                                                                                                                 093
//                                                                                                                                  
//                                                                                                                                  094
//                                                                                                                                      // Output XML for Jenkins CPPunit plugin
//                                                                                                                                      095
//                                                                                                                                          ofstream xmlFileOut("cppTestBasicMathResults.xml");
//                                                                                                                                          096
//                                                                                                                                              XmlOutputter xmlOut(&collectedresults, xmlFileOut);
//                                                                                                                                              097
//                                                                                                                                                  xmlOut.write();
//                                                                                                                                                  098
//                                                                                                                                                   
//                                                                                                                                                   099
//                                                                                                                                                       // return 0 if tests were successful
//                                                                                                                                                       100
//                                                                                                                                                           return collectedresults.wasSuccessful() ? 0 : 1;
//                                                                                                                                                           qkk1Gkk
