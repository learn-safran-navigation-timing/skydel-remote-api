
#include "SetGaussianNoisePowerDensityOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGaussianNoisePowerDensityOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGaussianNoisePowerDensityOffset::CmdName = "SetGaussianNoisePowerDensityOffset";
    const char* const SetGaussianNoisePowerDensityOffset::Documentation = "Set the Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density on the GNSS output (-174 dB/Hz). Default offset value is 0. If Gaussian Noise is not enabled on the output, this offset has no effect.\n"
      "\n"
      "Name               Type   Description\n"
      "------------------ ------ -------------------------------------------------------------------------------------\n"
      "Id                 string Target identifier\n"
      "OutputIdx          int    RF Output index (zero-based)\n"
      "PowerDensityOffset double Gaussian Noise power density offset (dB/Hz). Value must be between -10 and +10 dB/Hz.";
    const char* const SetGaussianNoisePowerDensityOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGaussianNoisePowerDensityOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGaussianNoisePowerDensityOffset);


    SetGaussianNoisePowerDensityOffset::SetGaussianNoisePowerDensityOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetGaussianNoisePowerDensityOffset::SetGaussianNoisePowerDensityOffset(const std::string& id, int outputIdx, double powerDensityOffset)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setOutputIdx(outputIdx);
      setPowerDensityOffset(powerDensityOffset);
    }

    SetGaussianNoisePowerDensityOffsetPtr SetGaussianNoisePowerDensityOffset::create(const std::string& id, int outputIdx, double powerDensityOffset)
    {
      return std::make_shared<SetGaussianNoisePowerDensityOffset>(id, outputIdx, powerDensityOffset);
    }

    SetGaussianNoisePowerDensityOffsetPtr SetGaussianNoisePowerDensityOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGaussianNoisePowerDensityOffset>(ptr);
    }

    bool SetGaussianNoisePowerDensityOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<double>::is_valid(m_values["PowerDensityOffset"])
        ;

    }

    std::string SetGaussianNoisePowerDensityOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGaussianNoisePowerDensityOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "OutputIdx", "PowerDensityOffset"}; 
      return names; 
    }


    int SetGaussianNoisePowerDensityOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGaussianNoisePowerDensityOffset::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetGaussianNoisePowerDensityOffset::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGaussianNoisePowerDensityOffset::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void SetGaussianNoisePowerDensityOffset::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGaussianNoisePowerDensityOffset::powerDensityOffset() const
    {
      return parse_json<double>::parse(m_values["PowerDensityOffset"]);
    }

    void SetGaussianNoisePowerDensityOffset::setPowerDensityOffset(double powerDensityOffset)
    {
      m_values.AddMember("PowerDensityOffset", parse_json<double>::format(powerDensityOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
