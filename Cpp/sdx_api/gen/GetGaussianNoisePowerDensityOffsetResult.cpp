
#include "GetGaussianNoisePowerDensityOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGaussianNoisePowerDensityOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGaussianNoisePowerDensityOffsetResult::CmdName = "GetGaussianNoisePowerDensityOffsetResult";
    const char* const GetGaussianNoisePowerDensityOffsetResult::Documentation = "Result of GetGaussianNoisePowerDensityOffset.\n"
      "\n"
      "Name               Type   Description\n"
      "------------------ ------ -------------------------------------------------------------------------------------\n"
      "Id                 string Target identifier\n"
      "OutputIdx          int    RF Output index (zero-based)\n"
      "PowerDensityOffset double Gaussian Noise power density offset (dB/Hz). Value must be between -10 and +10 dB/Hz.";
    const char* const GetGaussianNoisePowerDensityOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGaussianNoisePowerDensityOffsetResult);


    GetGaussianNoisePowerDensityOffsetResult::GetGaussianNoisePowerDensityOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGaussianNoisePowerDensityOffsetResult::GetGaussianNoisePowerDensityOffsetResult(const std::string& id, int outputIdx, double powerDensityOffset)
      : CommandResult(CmdName, TargetId)
    {

      setId(id);
      setOutputIdx(outputIdx);
      setPowerDensityOffset(powerDensityOffset);
    }

    GetGaussianNoisePowerDensityOffsetResult::GetGaussianNoisePowerDensityOffsetResult(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, double powerDensityOffset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setId(id);
      setOutputIdx(outputIdx);
      setPowerDensityOffset(powerDensityOffset);
    }


    GetGaussianNoisePowerDensityOffsetResultPtr GetGaussianNoisePowerDensityOffsetResult::create(const std::string& id, int outputIdx, double powerDensityOffset)
    {
      return std::make_shared<GetGaussianNoisePowerDensityOffsetResult>(id, outputIdx, powerDensityOffset);
    }

    GetGaussianNoisePowerDensityOffsetResultPtr GetGaussianNoisePowerDensityOffsetResult::create(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, double powerDensityOffset)
    {
      return std::make_shared<GetGaussianNoisePowerDensityOffsetResult>(relatedCommand, id, outputIdx, powerDensityOffset);
    }

    GetGaussianNoisePowerDensityOffsetResultPtr GetGaussianNoisePowerDensityOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGaussianNoisePowerDensityOffsetResult>(ptr);
    }

    bool GetGaussianNoisePowerDensityOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<double>::is_valid(m_values["PowerDensityOffset"])
        ;

    }

    std::string GetGaussianNoisePowerDensityOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGaussianNoisePowerDensityOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "OutputIdx", "PowerDensityOffset"}; 
      return names; 
    }


    std::string GetGaussianNoisePowerDensityOffsetResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGaussianNoisePowerDensityOffsetResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGaussianNoisePowerDensityOffsetResult::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void GetGaussianNoisePowerDensityOffsetResult::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGaussianNoisePowerDensityOffsetResult::powerDensityOffset() const
    {
      return parse_json<double>::parse(m_values["PowerDensityOffset"]);
    }

    void GetGaussianNoisePowerDensityOffsetResult::setPowerDensityOffset(double powerDensityOffset)
    {
      m_values.AddMember("PowerDensityOffset", parse_json<double>::format(powerDensityOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
