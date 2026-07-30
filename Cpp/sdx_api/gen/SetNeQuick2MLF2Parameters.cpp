
#include "SetNeQuick2MLF2Parameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNeQuick2MLF2Parameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNeQuick2MLF2Parameters::CmdName = "SetNeQuick2MLF2Parameters";
    const char* const SetNeQuick2MLF2Parameters::Documentation = "Set the parameters of the NeQuick2-MLF2 model.\n"
      "\n"
      "Name               Type   Description\n"
      "------------------ ------ -----------------------------------------------------------------------------------------------\n"
      "F10_7              double The Solar Radio Flux Index at 10.7cm Wavelength. Ranges from 0 to 400 s.f.u.\n"
      "Ap                 double The daily average of ap, converted to a linear scale. Ranges from 0 to 400.\n"
      "Kp                 double A global geomagnetic activity index quantifying disturbances in the horizontal, \n"
      "                          component of Earth's magnetic field. Ranges from 0 to 9.\n"
      "Smoothed_365_F10_7 double Solar Radio Flux Index at 10.7cm Wavelength smoothed over 365 days. Ranges from 0 to 400 s.f.u.";
    const char* const SetNeQuick2MLF2Parameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNeQuick2MLF2Parameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNeQuick2MLF2Parameters);


    SetNeQuick2MLF2Parameters::SetNeQuick2MLF2Parameters()
      : CommandBase(CmdName, TargetId)
    {}

    SetNeQuick2MLF2Parameters::SetNeQuick2MLF2Parameters(double f10_7, double ap, double kp, double smoothed_365_F10_7)
      : CommandBase(CmdName, TargetId)
    {

      setF10_7(f10_7);
      setAp(ap);
      setKp(kp);
      setSmoothed_365_F10_7(smoothed_365_F10_7);
    }

    SetNeQuick2MLF2ParametersPtr SetNeQuick2MLF2Parameters::create(double f10_7, double ap, double kp, double smoothed_365_F10_7)
    {
      return std::make_shared<SetNeQuick2MLF2Parameters>(f10_7, ap, kp, smoothed_365_F10_7);
    }

    SetNeQuick2MLF2ParametersPtr SetNeQuick2MLF2Parameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNeQuick2MLF2Parameters>(ptr);
    }

    bool SetNeQuick2MLF2Parameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["F10_7"])
          && parse_json<double>::is_valid(m_values["Ap"])
          && parse_json<double>::is_valid(m_values["Kp"])
          && parse_json<double>::is_valid(m_values["Smoothed_365_F10_7"])
        ;

    }

    std::string SetNeQuick2MLF2Parameters::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNeQuick2MLF2Parameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"F10_7", "Ap", "Kp", "Smoothed_365_F10_7"}; 
      return names; 
    }


    int SetNeQuick2MLF2Parameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetNeQuick2MLF2Parameters::f10_7() const
    {
      return parse_json<double>::parse(m_values["F10_7"]);
    }

    void SetNeQuick2MLF2Parameters::setF10_7(double f10_7)
    {
      setValue("F10_7", parse_json<double>::format(f10_7, m_values.GetAllocator()));
    }



    double SetNeQuick2MLF2Parameters::ap() const
    {
      return parse_json<double>::parse(m_values["Ap"]);
    }

    void SetNeQuick2MLF2Parameters::setAp(double ap)
    {
      setValue("Ap", parse_json<double>::format(ap, m_values.GetAllocator()));
    }



    double SetNeQuick2MLF2Parameters::kp() const
    {
      return parse_json<double>::parse(m_values["Kp"]);
    }

    void SetNeQuick2MLF2Parameters::setKp(double kp)
    {
      setValue("Kp", parse_json<double>::format(kp, m_values.GetAllocator()));
    }



    double SetNeQuick2MLF2Parameters::smoothed_365_F10_7() const
    {
      return parse_json<double>::parse(m_values["Smoothed_365_F10_7"]);
    }

    void SetNeQuick2MLF2Parameters::setSmoothed_365_F10_7(double smoothed_365_F10_7)
    {
      setValue("Smoothed_365_F10_7", parse_json<double>::format(smoothed_365_F10_7, m_values.GetAllocator()));
    }


  }
}
