
#include "GetPowerSbasOffsetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerSbasOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerSbasOffsetResult::CmdName = "GetPowerSbasOffsetResult";
    const char* const GetPowerSbasOffsetResult::Documentation = "Result of GetPowerSbasOffset.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------\n"
      "ServiceProvider string Service Provider key, allowed values: \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\"\n"
      "Offset          double Offset in dB (negative value will attenuate signal)";
    const char* const GetPowerSbasOffsetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPowerSbasOffsetResult);


    GetPowerSbasOffsetResult::GetPowerSbasOffsetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPowerSbasOffsetResult::GetPowerSbasOffsetResult(const std::string& serviceProvider, double offset)
      : CommandResult(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setOffset(offset);
    }

    GetPowerSbasOffsetResult::GetPowerSbasOffsetResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, double offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setServiceProvider(serviceProvider);
      setOffset(offset);
    }


    GetPowerSbasOffsetResultPtr GetPowerSbasOffsetResult::create(const std::string& serviceProvider, double offset)
    {
      return std::make_shared<GetPowerSbasOffsetResult>(serviceProvider, offset);
    }

    GetPowerSbasOffsetResultPtr GetPowerSbasOffsetResult::create(CommandBasePtr relatedCommand, const std::string& serviceProvider, double offset)
    {
      return std::make_shared<GetPowerSbasOffsetResult>(relatedCommand, serviceProvider, offset);
    }

    GetPowerSbasOffsetResultPtr GetPowerSbasOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerSbasOffsetResult>(ptr);
    }

    bool GetPowerSbasOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetPowerSbasOffsetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPowerSbasOffsetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Offset"}; 
      return names; 
    }


    std::string GetPowerSbasOffsetResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetPowerSbasOffsetResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerSbasOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPowerSbasOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
