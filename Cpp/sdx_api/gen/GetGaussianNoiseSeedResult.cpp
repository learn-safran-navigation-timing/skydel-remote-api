
#include "GetGaussianNoiseSeedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGaussianNoiseSeedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGaussianNoiseSeedResult::CmdName = "GetGaussianNoiseSeedResult";
    const char* const GetGaussianNoiseSeedResult::Documentation = "Result of GetGaussianNoiseSeed.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ -------------------------------------------------------------------------------\n"
      "Id        string Target identifier.\n"
      "OutputIdx int    RF Output index (zero-based).\n"
      "Seed      int    Gaussian Noise seed. Value must be a positive integer between 0 and 2147483647.";
    const char* const GetGaussianNoiseSeedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGaussianNoiseSeedResult);


    GetGaussianNoiseSeedResult::GetGaussianNoiseSeedResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGaussianNoiseSeedResult::GetGaussianNoiseSeedResult(const std::string& id, int outputIdx, int seed)
      : CommandResult(CmdName, TargetId)
    {

      setId(id);
      setOutputIdx(outputIdx);
      setSeed(seed);
    }

    GetGaussianNoiseSeedResult::GetGaussianNoiseSeedResult(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, int seed)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setId(id);
      setOutputIdx(outputIdx);
      setSeed(seed);
    }


    GetGaussianNoiseSeedResultPtr GetGaussianNoiseSeedResult::create(const std::string& id, int outputIdx, int seed)
    {
      return std::make_shared<GetGaussianNoiseSeedResult>(id, outputIdx, seed);
    }

    GetGaussianNoiseSeedResultPtr GetGaussianNoiseSeedResult::create(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, int seed)
    {
      return std::make_shared<GetGaussianNoiseSeedResult>(relatedCommand, id, outputIdx, seed);
    }

    GetGaussianNoiseSeedResultPtr GetGaussianNoiseSeedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGaussianNoiseSeedResult>(ptr);
    }

    bool GetGaussianNoiseSeedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<int>::is_valid(m_values["Seed"])
        ;

    }

    std::string GetGaussianNoiseSeedResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGaussianNoiseSeedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "OutputIdx", "Seed"}; 
      return names; 
    }


    std::string GetGaussianNoiseSeedResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGaussianNoiseSeedResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGaussianNoiseSeedResult::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void GetGaussianNoiseSeedResult::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGaussianNoiseSeedResult::seed() const
    {
      return parse_json<int>::parse(m_values["Seed"]);
    }

    void GetGaussianNoiseSeedResult::setSeed(int seed)
    {
      m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
