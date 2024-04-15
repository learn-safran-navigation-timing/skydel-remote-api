
#include "RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::CmdName = "RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV";
    const char* const RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::Documentation = "Generate new seeds for pseudorange noise Gauss-Markov process error on all satellites.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV);


    RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV()
      : CommandBase(CmdName, TargetId)
    {}

    RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    RandomizePseudorangeNoiseGaussMarkovSeedsForAllSVPtr RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::create(const std::string& system)
    {
      return std::make_shared<RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV>(system);
    }

    RandomizePseudorangeNoiseGaussMarkovSeedsForAllSVPtr RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV>(ptr);
    }

    bool RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::documentation() const { return Documentation; }

    const std::vector<std::string>& RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
