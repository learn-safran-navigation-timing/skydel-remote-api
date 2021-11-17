#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGlonassDoubleParam is deprecated since 21.3. You may use GetGlonassEphDoubleParamForSV.
    /// 
    /// Get various parameters for GLONASS
    /// 
    ///   ParamName       Unit               Range          Description
    ///   "TauC"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time
    ///   "TauGps"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time
    ///   "TauN"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time
    ///   "TLambda"       sec                0..44100       Time of the first ascending node passage
    ///   "Lambda"        semicircle         +/- 1          Longitude of the first ascending node
    ///   "DeltaI"        semicircle         +/- 0.067      Correction to the mean value of inclination
    ///   "Omega"         semicircle         +/- 1          Argument of perigee
    ///   "Eccentricity"  -                  0..0.03        Eccentricity
    ///   "DeltaT"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period
    ///   "DeltaTRate"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------------------
    /// Prn       int    Satellite PRN (slot number) 1..24, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    ///

    class GetGlonassDoubleParam;
    typedef std::shared_ptr<GetGlonassDoubleParam> GetGlonassDoubleParamPtr;
    
    
    class GetGlonassDoubleParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassDoubleParam();

      GetGlonassDoubleParam(int prn, const std::string& paramName);
  
      static GetGlonassDoubleParamPtr create(int prn, const std::string& paramName);
      static GetGlonassDoubleParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);
    };
  }
}

