
#include "SetGaussianNoiseSeed.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGaussianNoiseSeed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGaussianNoiseSeed::CmdName = "SetGaussianNoiseSeed";
    const char* const SetGaussianNoiseSeed::Documentation = "Set the seed used to generate the Gaussian Noise. Gaussian Noise must be enabled on the output. It is optional to set the seed of an output. By default, the seed value used is the index of the output.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ -------------------------------------------------------------------------------\n"
      "Id        string Target identifier.\n"
      "OutputIdx int    RF Output index (zero-based).\n"
      "Seed      int    Gaussian Noise seed. Value must be a positive integer between 0 and 2147483647.";
    const char* const SetGaussianNoiseSeed::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGaussianNoiseSeed);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGaussianNoiseSeed);


    SetGaussianNoiseSeed::SetGaussianNoiseSeed()
      : CommandBase(CmdName, TargetId)
    {}

    SetGaussianNoiseSeed::SetGaussianNoiseSeed(const std::string& id, int outputIdx, int seed)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setOutputIdx(outputIdx);
      setSeed(seed);
    }

    SetGaussianNoiseSeedPtr SetGaussianNoiseSeed::create(const std::string& id, int outputIdx, int seed)
    {
      return std::make_shared<SetGaussianNoiseSeed>(id, outputIdx, seed);
    }

    SetGaussianNoiseSeedPtr SetGaussianNoiseSeed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGaussianNoiseSeed>(ptr);
    }

    bool SetGaussianNoiseSeed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<int>::is_valid(m_values["Seed"])
        ;

    }

    std::string SetGaussianNoiseSeed::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGaussianNoiseSeed::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "OutputIdx", "Seed"}; 
      return names; 
    }


    int SetGaussianNoiseSeed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGaussianNoiseSeed::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetGaussianNoiseSeed::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGaussianNoiseSeed::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void SetGaussianNoiseSeed::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGaussianNoiseSeed::seed() const
    {
      return parse_json<int>::parse(m_values["Seed"]);
    }

    void SetGaussianNoiseSeed::setSeed(int seed)
    {
      m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
