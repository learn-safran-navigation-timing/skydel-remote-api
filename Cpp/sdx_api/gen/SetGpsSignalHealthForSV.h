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
    /// Set GPS signal health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// Health      int             Signal health 0..31
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsSignalHealthForSV;
    typedef std::shared_ptr<SetGpsSignalHealthForSV> SetGpsSignalHealthForSVPtr;
    
    
    class SetGpsSignalHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpsSignalHealthForSV();

      SetGpsSignalHealthForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static SetGpsSignalHealthForSVPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static SetGpsSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

