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
    /// Set BeiDou satellite autonomous health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// Health      bool            Status, false = Good, true = Not Good
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetBeiDouAutonomousHealthForSV;
    typedef std::shared_ptr<SetBeiDouAutonomousHealthForSV> SetBeiDouAutonomousHealthForSVPtr;
    
    
    class SetBeiDouAutonomousHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetBeiDouAutonomousHealthForSV();

      SetBeiDouAutonomousHealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static SetBeiDouAutonomousHealthForSVPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static SetBeiDouAutonomousHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

