#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <catch2/catch.hpp>
#include <cieo/logging.hpp>

int main( int argc, char* argv[] )
{
  Catch::Session session;

  cieo::logger::register_sink<cieo::logger::StderrColorSink>();
  cieo::logger::initialize_core_logger();

  int returnCode = session.applyCommandLine( argc, argv );
  if( returnCode != 0 )
        return returnCode;
  int numFailed = session.run();
  return numFailed;
}

// end catch_default_main.hpp
