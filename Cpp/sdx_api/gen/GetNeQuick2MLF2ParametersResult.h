#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNeQuick2MLF2Parameters.
    ///
    /// Name               Type   Description
    /// ------------------ ------ -----------------------------------------------------------------------------------------------
    /// F10_7              double The Solar Radio Flux Index at 10.7cm Wavelength. Ranges from 0 to 400 s.f.u.
    /// Ap                 double The daily average of ap, converted to a linear scale. Ranges from 0 to 400.
    /// Kp                 double A global geomagnetic activity index quantifying disturbances in the horizontal, 
    ///                           component of Earth's magnetic field. Ranges from 0 to 9.
    /// Smoothed_365_F10_7 double Solar Radio Flux Index at 10.7cm Wavelength smoothed over 365 days. Ranges from 0 to 400 s.f.u.
    ///

    class GetNeQuick2MLF2ParametersResult;
    typedef std::shared_ptr<GetNeQuick2MLF2ParametersResult> GetNeQuick2MLF2ParametersResultPtr;
    
    
    class GetNeQuick2MLF2ParametersResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNeQuick2MLF2ParametersResult();

      GetNeQuick2MLF2ParametersResult(double f10_7, double ap, double kp, double smoothed_365_F10_7);

      GetNeQuick2MLF2ParametersResult(CommandBasePtr relatedCommand, double f10_7, double ap, double kp, double smoothed_365_F10_7);

      static GetNeQuick2MLF2ParametersResultPtr create(double f10_7, double ap, double kp, double smoothed_365_F10_7);

      static GetNeQuick2MLF2ParametersResultPtr create(CommandBasePtr relatedCommand, double f10_7, double ap, double kp, double smoothed_365_F10_7);
      static GetNeQuick2MLF2ParametersResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** f10_7 ****
      double f10_7() const;
      void setF10_7(double f10_7);


      // **** ap ****
      double ap() const;
      void setAp(double ap);


      // **** kp ****
      double kp() const;
      void setKp(double kp);


      // **** smoothed_365_F10_7 ****
      double smoothed_365_F10_7() const;
      void setSmoothed_365_F10_7(double smoothed_365_F10_7);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNeQuick2MLF2ParametersResult);
  }
}

