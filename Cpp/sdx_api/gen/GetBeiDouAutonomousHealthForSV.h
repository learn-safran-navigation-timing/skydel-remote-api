#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou satellite autonomous health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouAutonomousHealthForSV;
    typedef std::shared_ptr<GetBeiDouAutonomousHealthForSV> GetBeiDouAutonomousHealthForSVPtr;
    
    
    class GetBeiDouAutonomousHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetBeiDouAutonomousHealthForSV();

      GetBeiDouAutonomousHealthForSV(int svId, const std::optional<std::string>& dataSetName = {});

      static GetBeiDouAutonomousHealthForSVPtr create(int svId, const std::optional<std::string>& dataSetName = {});
      static GetBeiDouAutonomousHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

