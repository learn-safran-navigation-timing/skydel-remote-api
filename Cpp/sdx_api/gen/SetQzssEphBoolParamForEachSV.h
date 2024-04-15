#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.
    /// 
    /// Set QZSS ephemeris boolean parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssEphBoolParamForEachSV;
    typedef std::shared_ptr<SetQzssEphBoolParamForEachSV> SetQzssEphBoolParamForEachSVPtr;
    
    
    class SetQzssEphBoolParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      SetQzssEphBoolParamForEachSV();

      SetQzssEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      static SetQzssEphBoolParamForEachSVPtr create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssEphBoolParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<bool> val() const;
      void setVal(const std::vector<bool>& val);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

