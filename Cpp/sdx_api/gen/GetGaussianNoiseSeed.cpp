
#include "GetGaussianNoiseSeed.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGaussianNoiseSeed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGaussianNoiseSeed::CmdName = "GetGaussianNoiseSeed";
    const char* const GetGaussianNoiseSeed::Documentation = "Get the seed used to generate the Gaussian Noise. Gaussian Noise must be enabled on the output. It is optional to set the seed of an output. By default, the seed value used is the index of the output.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ -----------------------------\n"
      "Id        string Target identifier.\n"
      "OutputIdx int    RF Output index (zero-based).";
    const char* const GetGaussianNoiseSeed::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGaussianNoiseSeed);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGaussianNoiseSeed);


    GetGaussianNoiseSeed::GetGaussianNoiseSeed()
      : CommandBase(CmdName, TargetId)
    {}

    GetGaussianNoiseSeed::GetGaussianNoiseSeed(const std::string& id, int outputIdx)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setOutputIdx(outputIdx);
    }

    GetGaussianNoiseSeedPtr GetGaussianNoiseSeed::create(const std::string& id, int outputIdx)
    {
      return std::make_shared<GetGaussianNoiseSeed>(id, outputIdx);
    }

    GetGaussianNoiseSeedPtr GetGaussianNoiseSeed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGaussianNoiseSeed>(ptr);
    }

    bool GetGaussianNoiseSeed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
        ;

    }

    std::string GetGaussianNoiseSeed::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGaussianNoiseSeed::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "OutputIdx"}; 
      return names; 
    }


    int GetGaussianNoiseSeed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGaussianNoiseSeed::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGaussianNoiseSeed::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGaussianNoiseSeed::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void GetGaussianNoiseSeed::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
