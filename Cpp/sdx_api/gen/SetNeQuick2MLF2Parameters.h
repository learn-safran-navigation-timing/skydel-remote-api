#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the parameters of the NeQuick2-MLF2 model.
    ///
    /// Name               Type   Description
    /// ------------------ ------ -----------------------------------------------------------------------------------------------
    /// F10_7              double The Solar Radio Flux Index at 10.7cm Wavelength. Ranges from 0 to 400 s.f.u.
    /// Ap                 double The daily average of ap, converted to a linear scale. Ranges from 0 to 400.
    /// Kp                 double A global geomagnetic activity index quantifying disturbances in the horizontal, 
    ///                           component of Earth's magnetic field. Ranges from 0 to 9.
    /// Smoothed_365_F10_7 double Solar Radio Flux Index at 10.7cm Wavelength smoothed over 365 days. Ranges from 0 to 400 s.f.u.
    ///

    class SetNeQuick2MLF2Parameters;
    typedef std::shared_ptr<SetNeQuick2MLF2Parameters> SetNeQuick2MLF2ParametersPtr;
    
    
    class SetNeQuick2MLF2Parameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetNeQuick2MLF2Parameters();

      SetNeQuick2MLF2Parameters(double f10_7, double ap, double kp, double smoothed_365_F10_7);

      static SetNeQuick2MLF2ParametersPtr create(double f10_7, double ap, double kp, double smoothed_365_F10_7);
      static SetNeQuick2MLF2ParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

