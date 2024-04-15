
#include "GetGaussianNoisePowerDensityOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGaussianNoisePowerDensityOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGaussianNoisePowerDensityOffset::CmdName = "GetGaussianNoisePowerDensityOffset";
    const char* const GetGaussianNoisePowerDensityOffset::Documentation = "Get the Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density on the GNSS output (-174 dB/Hz). Default offset value is 0. If Gaussian Noise is not enabled on the output, this offset has no effect.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ ----------------------------\n"
      "Id        string Target identifier\n"
      "OutputIdx int    RF Output index (zero-based)";
    const char* const GetGaussianNoisePowerDensityOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGaussianNoisePowerDensityOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGaussianNoisePowerDensityOffset);


    GetGaussianNoisePowerDensityOffset::GetGaussianNoisePowerDensityOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetGaussianNoisePowerDensityOffset::GetGaussianNoisePowerDensityOffset(const std::string& id, int outputIdx)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setOutputIdx(outputIdx);
    }

    GetGaussianNoisePowerDensityOffsetPtr GetGaussianNoisePowerDensityOffset::create(const std::string& id, int outputIdx)
    {
      return std::make_shared<GetGaussianNoisePowerDensityOffset>(id, outputIdx);
    }

    GetGaussianNoisePowerDensityOffsetPtr GetGaussianNoisePowerDensityOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGaussianNoisePowerDensityOffset>(ptr);
    }

    bool GetGaussianNoisePowerDensityOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
        ;

    }

    std::string GetGaussianNoisePowerDensityOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGaussianNoisePowerDensityOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "OutputIdx"}; 
      return names; 
    }


    int GetGaussianNoisePowerDensityOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGaussianNoisePowerDensityOffset::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGaussianNoisePowerDensityOffset::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGaussianNoisePowerDensityOffset::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void GetGaussianNoisePowerDensityOffset::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
