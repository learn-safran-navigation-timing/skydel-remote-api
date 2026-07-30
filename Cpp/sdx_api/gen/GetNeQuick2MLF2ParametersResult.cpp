
#include "GetNeQuick2MLF2ParametersResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNeQuick2MLF2ParametersResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNeQuick2MLF2ParametersResult::CmdName = "GetNeQuick2MLF2ParametersResult";
    const char* const GetNeQuick2MLF2ParametersResult::Documentation = "Result of GetNeQuick2MLF2Parameters.\n"
      "\n"
      "Name               Type   Description\n"
      "------------------ ------ -----------------------------------------------------------------------------------------------\n"
      "F10_7              double The Solar Radio Flux Index at 10.7cm Wavelength. Ranges from 0 to 400 s.f.u.\n"
      "Ap                 double The daily average of ap, converted to a linear scale. Ranges from 0 to 400.\n"
      "Kp                 double A global geomagnetic activity index quantifying disturbances in the horizontal, \n"
      "                          component of Earth's magnetic field. Ranges from 0 to 9.\n"
      "Smoothed_365_F10_7 double Solar Radio Flux Index at 10.7cm Wavelength smoothed over 365 days. Ranges from 0 to 400 s.f.u.";
    const char* const GetNeQuick2MLF2ParametersResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNeQuick2MLF2ParametersResult);


    GetNeQuick2MLF2ParametersResult::GetNeQuick2MLF2ParametersResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNeQuick2MLF2ParametersResult::GetNeQuick2MLF2ParametersResult(double f10_7, double ap, double kp, double smoothed_365_F10_7)
      : CommandResult(CmdName, TargetId)
    {

      setF10_7(f10_7);
      setAp(ap);
      setKp(kp);
      setSmoothed_365_F10_7(smoothed_365_F10_7);
    }

    GetNeQuick2MLF2ParametersResult::GetNeQuick2MLF2ParametersResult(CommandBasePtr relatedCommand, double f10_7, double ap, double kp, double smoothed_365_F10_7)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setF10_7(f10_7);
      setAp(ap);
      setKp(kp);
      setSmoothed_365_F10_7(smoothed_365_F10_7);
    }


    GetNeQuick2MLF2ParametersResultPtr GetNeQuick2MLF2ParametersResult::create(double f10_7, double ap, double kp, double smoothed_365_F10_7)
    {
      return std::make_shared<GetNeQuick2MLF2ParametersResult>(f10_7, ap, kp, smoothed_365_F10_7);
    }

    GetNeQuick2MLF2ParametersResultPtr GetNeQuick2MLF2ParametersResult::create(CommandBasePtr relatedCommand, double f10_7, double ap, double kp, double smoothed_365_F10_7)
    {
      return std::make_shared<GetNeQuick2MLF2ParametersResult>(relatedCommand, f10_7, ap, kp, smoothed_365_F10_7);
    }

    GetNeQuick2MLF2ParametersResultPtr GetNeQuick2MLF2ParametersResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNeQuick2MLF2ParametersResult>(ptr);
    }

    bool GetNeQuick2MLF2ParametersResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["F10_7"])
          && parse_json<double>::is_valid(m_values["Ap"])
          && parse_json<double>::is_valid(m_values["Kp"])
          && parse_json<double>::is_valid(m_values["Smoothed_365_F10_7"])
        ;

    }

    std::string GetNeQuick2MLF2ParametersResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNeQuick2MLF2ParametersResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"F10_7", "Ap", "Kp", "Smoothed_365_F10_7"}; 
      return names; 
    }


    double GetNeQuick2MLF2ParametersResult::f10_7() const
    {
      return parse_json<double>::parse(m_values["F10_7"]);
    }

    void GetNeQuick2MLF2ParametersResult::setF10_7(double f10_7)
    {
      setValue("F10_7", parse_json<double>::format(f10_7, m_values.GetAllocator()));
    }



    double GetNeQuick2MLF2ParametersResult::ap() const
    {
      return parse_json<double>::parse(m_values["Ap"]);
    }

    void GetNeQuick2MLF2ParametersResult::setAp(double ap)
    {
      setValue("Ap", parse_json<double>::format(ap, m_values.GetAllocator()));
    }



    double GetNeQuick2MLF2ParametersResult::kp() const
    {
      return parse_json<double>::parse(m_values["Kp"]);
    }

    void GetNeQuick2MLF2ParametersResult::setKp(double kp)
    {
      setValue("Kp", parse_json<double>::format(kp, m_values.GetAllocator()));
    }



    double GetNeQuick2MLF2ParametersResult::smoothed_365_F10_7() const
    {
      return parse_json<double>::parse(m_values["Smoothed_365_F10_7"]);
    }

    void GetNeQuick2MLF2ParametersResult::setSmoothed_365_F10_7(double smoothed_365_F10_7)
    {
      setValue("Smoothed_365_F10_7", parse_json<double>::format(smoothed_365_F10_7, m_values.GetAllocator()));
    }


  }
}
