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
    /// Set GPS nav data health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// Health      int             Data health 0..7
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsDataHealthForSV;
    typedef std::shared_ptr<SetGpsDataHealthForSV> SetGpsDataHealthForSVPtr;
    
    
    class SetGpsDataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpsDataHealthForSV();

      SetGpsDataHealthForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static SetGpsDataHealthForSVPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static SetGpsDataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

