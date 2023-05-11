#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Skydel special calibration function, internal use only
    ///
    /// Name          Type   Description
    /// ------------- ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// SvId          int    SV ID for GPS, Galileo, BeiDou, GLONASS, QZSS and SBAS.
    /// Signal        string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S"
    /// EnableSV      bool   Enable/Disable multiplication by satellite and Navigation Message
    /// EnableDoppler bool   Enable/Disable Doppler Frequency and Phase offset
    /// PhaseOffet    double Carrier Phase Offset applied to Line Of Sight
    ///

    class CalibFunction;
    typedef std::shared_ptr<CalibFunction> CalibFunctionPtr;
    
    
    class CalibFunction : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      CalibFunction();

      CalibFunction(int svId, const std::string& signal, bool enableSV, bool enableDoppler, double phaseOffet);

      static CalibFunctionPtr create(int svId, const std::string& signal, bool enableSV, bool enableDoppler, double phaseOffet);
      static CalibFunctionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enableSV ****
      bool enableSV() const;
      void setEnableSV(bool enableSV);


      // **** enableDoppler ****
      bool enableDoppler() const;
      void setEnableDoppler(bool enableDoppler);


      // **** phaseOffet ****
      double phaseOffet() const;
      void setPhaseOffet(double phaseOffet);
    };
    
  }
}

