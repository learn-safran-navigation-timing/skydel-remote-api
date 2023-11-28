#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssEphemerisDoubleParam is deprecated since 21.3. You may use SetQzssEphDoubleParamForSV.
    /// 
    /// Please note the command SetQzssEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.
    /// 
    /// Set various parameters in the QZSS ephemeris.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)
    /// ParamName   string          In meters:  "Crs", "Crc"
    ///                             In radians: "Cis", "Cic", "Cus", "Cuc"
    ///                             In seconds: "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
    /// Val         double          Parameter value (see ParamName above for unit)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssEphemerisDoubleParam;
    typedef std::shared_ptr<SetQzssEphemerisDoubleParam> SetQzssEphemerisDoubleParamPtr;
    
    
    class SetQzssEphemerisDoubleParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      SetQzssEphemerisDoubleParam();

      SetQzssEphemerisDoubleParam(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssEphemerisDoubleParamPtr create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssEphemerisDoubleParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      double val() const;
      void setVal(double val);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

