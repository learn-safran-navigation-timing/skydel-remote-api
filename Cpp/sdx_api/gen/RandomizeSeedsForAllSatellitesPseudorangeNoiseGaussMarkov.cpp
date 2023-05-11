
#include "gen/RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::CmdName = "RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov";
    const char* const RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::Documentation = "Please note the command RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV.\n\nGenerate new seeds for pseudorange noise Gauss-Markov process error on all satellites.";

    REGISTER_COMMAND_FACTORY(RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov);


    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov()
      : CommandBase(CmdName)
    {}

    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::create(const std::string& system)
    {
      return std::make_shared<RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov>(system);
    }

    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov>(ptr);
    }

    bool RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::documentation() const { return Documentation; }


    int RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
